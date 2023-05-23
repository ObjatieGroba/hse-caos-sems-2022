#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <vector>


struct X {
    int x = 0;

    ~X() {
        std::cerr << "Hello" << std::endl;
    }
} x;

std::mutex mx;
std::mutex mx2;
std::condition_variable cv;

struct Client {
    int money = 0;
    std::mutex mx;
};

std::vector<Client> clients(2);

void process(size_t i, size_t j, int k) {
//    std::unique_lock locki(client[i].mx);
//    std::unique_lock lockj(client[j].mx);
//    std::lock(client[i].mx, client[j].mx);

    std::unique_lock locki(client[std::min(i, j)].mx);
    std::unique_lock lockj(client[std::max(i, j)].mx);

    clients[i].money -= k;
    clients[j].money += k;
}

void func() {
//    mx.lock();
    std::unique_lock lock(mx);
//    cv.wait(lock, []{return x.x % 2 == 0;});
    while (x.x % 2 != 0) {
        cv.wait(lock);
    }
    std::cout << x.x << '\n';
    ++x.x;
    ++x.x;
//    mx.unlock();
}

void dunc() {
//    mx.lock();
    std::unique_lock lock(mx);
    ++x.x;
//    mx.unlock();
}


int main() {
    std::thread t([](){
        for (size_t i = 0; i != 10000; ++i) {
            dunc();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cerr << x.x << std::endl;
        cv.notify_one();
    });

    for (size_t i = 0; i != 10000; ++i) {
        func();
    }
//    t.detach();
    t.join();
}
