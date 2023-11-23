#include <atomic>
#include <iostream>

std::atomic<int> x;
std::atomic<int[100]> xm;  -- mutex
int y;

void g() {
    //// G BEFORE
    y = 2;
    x.store(1);
    //// G AFTER
}

void f() {
    //// F BEFORE
    x.load();
    std::cout << y << std::endl;
    //// F AFTER
}

int main() {
    _Atomic int x = 0;
    int y = 0;
    ++x;
    ++y;
    ++y;
    for (...) {
        int z = x;
    }
}