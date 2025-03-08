#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#endif
#include <stdio.h>
int main()
{

#if defined(_WIN32)
    WSADATA d;
    if WSAStartup (MAKEWORK(2, 2), &d)
    {
        fprintf(stderr, "Failed to initialized\n");
        return 1;
    }
#endif
    printf("Ready to use the Socket \n");
#if defined(_WIN32)
    WSACleanup();

#endif
}
