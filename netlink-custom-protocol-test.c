#include <stdio.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define NETLINK_TEST 24
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static int protocols[3] = {NETLINK_TEST, NETLINK_GENERIC, NETLINK_CONNECTOR};

static char *protocol_names[ARRAY_SIZE(protocols)] = {
    "NETLINK_TEST", "NETLINK_GENERIC", "NETLINK_CONNECTOR"};

const char *protocol_name(int protocol)
{
        int i;
        for (i = 0; i < ARRAY_SIZE(protocols); i++) {
                if (protocols[i] == protocol) {
                        return protocol_names[i];
                }
        }
        return "UNKNOWN";
}

int main(int argc, char* argv[])
{
        int i;
        for (i = 0; i < ARRAY_SIZE(protocols); i++) {
                int protocol = protocols[i];
                int fd = socket(AF_NETLINK, SOCK_RAW, protocol);
                if(fd == -1) {
                        printf("socket(AF_NETLINK, SOCK_RAW, %s) error!: %s\n",
                               protocol_name(protocol), strerror(errno));
                } else {
                        printf("socket(AF_NETLINK, SOCK_RAW, %s) success!\n",
                               protocol_name(protocol));
                        close(fd);
                }
        }
        return 0;
}
