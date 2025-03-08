
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1)
    {
        printf("getifaddrs call failed \n");
        return -1;
    }
    // p

    while (addresses)
    {
        int family = addresses->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6)
        {
            printf("%s \t", addresses->ifa_name);
            printf("%s \t", family == AF_INET ? "IPV4" : "IPV6");

            char ap[100];
            char b[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(addresses->ifa_addr, family_size, ap, sizeof(ap), b, sizeof(b), NI_NUMERICHOST);
            printf("%s \n", ap);
        }
        addresses = addresses->ifa_next;
    }
    freeifaddrs(addresses);
}