#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>


struct Client {
    int money = 10;
    std::mutex mx;
};

std::mutex mx;
std::condition_variable cv;
std::vector<Client> clients(20);


void process(size_t i, size_t j, int k) {
//    std::unique_lock lock(mx);
//    mx.lock();
//    while (clients[i].money < k) {
//        cv.wait(lock);
//    }
//    cv.wait(lock, [&](){return clients[i].money >= k;});

//    if (clients[i].money < k) {
//        throw std::runtime_error("aa");
//    }
//    std::lock(clients[i].mx, clients[j].mx);
    std::unique_lock locki(clients[std::min(i, j)].mx);
    std::unique_lock lockj(clients[std::max(i, j)].mx);
    clients[i].money -= k;
    clients[j].money += k;

//    clients[i].mx.unlock();
//    clients[j].mx.unlock();
//    cv.notify_all();
//    mx.unlock();
}


int main() {
    std::thread t([](){
        for (size_t i = 0; i != 100000; ++i) {
            process(0, 1, 10);
        }
        std::cout << "2\n";
    });
    for (size_t i = 0; i != 100000; ++i) {
        process(1, 0, 10);
    }
    t.join();
//    t.detach();
    std::cout << "1\n";
    std::cout << clients[0].money << ' ' << clients[1].money << std::endl;
}
