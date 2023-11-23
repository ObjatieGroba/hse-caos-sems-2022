#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>

Action Context::switch_context(Action action) {
    /// TODO
    /// swap esp and this->esp
    /// swap eip and this->eip
    /// move action through switch

    /// 32bit x86 ASM only!

    auto * peip = &eip;

    "lea -12(%ebp) %eax"
    asm volatile("push ebp"
                 "swap 4(%eax), esp\n\t"

                 "swap 0(eax), eip\n\t"

                 "mov 0(eax) %esi\n"
                 "mov label, 0(eax)\n"
                 "jmp *%%esi\n"

                 "" /// Before jmp
                 ""
                 "label:" /// After jmp
                 "pop ebp" : "a"(this) : : "memory", "cc",
                 "ebx", "ecx", "edx",
                 "esi", "edi");
    return action;
}

void *FiberScheduler::yield(void *data) {
    /// TODO
    /// current_scheduler->sched_context
    /// queue.push(cur_context); --- НЕЛЬЗЯ
//    current_scheduler->sched_context.switch_context();
    ///cur_context

    queue.push(current_scheduler->sched_context);
//    current_scheduler->sched_context.switch_context();
//    auto sched = current_scheduler->sched_context;
    queue.back().switch_context();
//    current_scheduler->sched_context.switch_context();
//    Queue.back() == cur_context
}

int main() {
    int fd = open("file.txt",
                  O_CREAT | O_RDWR,
                  0600);
    if (fd < 0) {
        printf("Failed to open\n");
        return 1;
    }
    errno = 0;
    char * addr = mmap(NULL, 16,
                       PROT_WRITE | PROT_READ,
                       MAP_SHARED,
                        fd, 0);
    printf("%p %d\n", addr, errno);
    // char t[] = "awdjnnaiwbdliawidbakd";
    // write(fd, t, sizeof(t) - 1);
    addr[10] = 'b';
    addr[26] = 'c';
    scanf("%d", &errno);

    int x;
    struct Anon {
        int &x;
        int c;

        auto operator()(int y) {
            return x + y + c;
        }
    };
    auto f = [&x, c=x](int y) -> int {
        return x + y + c;
    };
    return f;
}
