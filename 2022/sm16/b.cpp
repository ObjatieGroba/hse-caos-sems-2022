#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/epoll.h>


class FdHolder {
public:
    int fd;
};


class Listener : FdHolder {
    ....
};


class Client : FdHolder {
public:
    void event(epoll_event ev) {
        if (ev.events | EPOLLIN) {
            rbuf.read(fd);
            /// Бизнес логика клиента
        } else if (ev.events | EPOLLOUT) {
            wbuf.write(fd);
        } else if (ev.events | EPOLLERR) {
            ///
        }
    }

private:
    ReadBuf rbuf;
    WriteBuf wbuf;
};

int main() {
    int epoll_fd = epoll_create1(0);

    epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.ptr = new FdHolder{0};
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ((Client*)(ev.data.ptr))->fd, &ev);


    epoll_wait(...);
    ev.data.ptr == FdHolder*
}