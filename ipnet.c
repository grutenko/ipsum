#include "ipnet.h"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int ipnet_parse(ipnet_t *ipnet, const char *str) {
        char *slash = strchr(str, '/');
        if (slash) {
                *slash = '\0';
                ipnet->cidr = atoi(slash + 1);
        } else {
                ipnet->cidr = 32;
        }
        if (ipnet->cidr < 0 || ipnet->cidr > 32 ||
            (ipnet->ip & ipnet_mask(ipnet->cidr)) != ipnet->ip) {
                return 0;
        }
        ipnet->ip = inet_addr(str);
        if (ipnet->ip == INADDR_NONE) {
                return 0;
        }
        return 1;
}

int ipnet_to_str(ipnet_t *ipnet, char *buf, size_t len) {
        if (len < 16) {
                return -1;
        }
        struct in_addr addr;
        addr.s_addr = ipnet->ip;
        if (ipnet->cidr == 32) {
                snprintf(buf, len, "%s", inet_ntoa(addr));
        } else {
                snprintf(buf, len, "%s/%d", inet_ntoa(addr), ipnet->cidr);
        }
        return strlen(buf);
}
