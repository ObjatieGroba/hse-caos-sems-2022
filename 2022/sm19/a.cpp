#include <iostream>
#include <atomic>
#include <vector>

//struct S {
//    int a[100500];
//};
//std::atomic<S> a;

std::atomic<int> g = 1;

void lock() {

//    while (g.load() == 0) {
//        ;
//    }
//    g.store(0);
    while (g.exchange(0) == 0) {
        ;
    }
}

void unlock() {
    g.store(1);
}


int main() {

}
