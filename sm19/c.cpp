#include <mutex>
#include <atomic>

struct DB {
    int x = 0;
    int y = 0;
    std::mutex mx;
} db;

void inc() {
    ++x;
    if (x + y % 2) {
        ++y;
    }
}

void atomic_inc() {
    std::unique_lock lock(db.mx);  /// db.mx.lock();
    inc();
    // ~lock   db.mx.unlock();
}


std::atomic<int> spinlock = 0;

void lock() {
//    while (spinlock != 0) {
//
//    }
//    spinlock = 1;
    while (spinlock.exchange(1) == 1) {

    }
}

void unlock() {
    spinlock = 0;
}

int i;
std::atomic<int> j;

void dunc(int b, int a) {
    if (i == b) {
        i = a;
    }
    j.compare_exchange_strong(b, a);
    /// var b contains current j value if j was not b
}
