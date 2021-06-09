#include <stdio.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <unistd.h>
#define NETLINK_TEST 24
int sock_fd;
int main(int argc, char* argv[])
{
    sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_TEST);
    if(sock_fd > 0)
        close(sock_fd);
    else {
        printf("socket AF_NETLINK error!\n");
        return -1;
    }
    return 0;
}
