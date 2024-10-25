#include "includes/includes.hpp"

int main(void)
{
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    int listenfd;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
}