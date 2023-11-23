#include <atomic>

//thread_local int x;


struct LockFreeStack {
//    LockFreeStack(size_t max_elems) : elems(max_elems) {}
//    std::vector<int> elems;
//    std::atomic<int> end = 0;
//    void push(int x) {
//        size_t prev = end.fetch_add(1); /// 1
//        elems[prev] = x; /// 4
//    }
//    int pop() {
//        size_t prev = end.fetch_sub(1); /// 2
//        return elems[prev];  /// 3
//    }
    struct Node {
        Node * next = nullptr;
        int val = 0;
    };

    std::atomic<Node *> head;

    void push(int x) {
        auto node = new Node{nullptr, x};
        {
            node->next = head.load();
            while (!head.compare_exchange_strong(node->next, node)) {
            }
        }
    }
    int pop() {
        Node * tmp;
        {
            tmp = head.load();
            while (!head.compare_exchange_strong(tmp, tmp->next)) {
            }
        }
        auto res = tmp->val;
        delete tmp;
        return res;
    }
};
