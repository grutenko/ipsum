#ifndef ipnet_h
#define ipnet_h

#include <stdlib.h>

typedef struct ipnet {
        unsigned ip;
        unsigned cidr;
        struct ipnet *next;
        struct ipnet *prev;
} ipnet_t;

/**
 * Returns the mask for a given CIDR.
 * The mask is a 32-bit unsigned integer where the first `cidr` bits are set to
 * 1, and the remaining bits are set to 0. For example, for CIDR /24, the mask
 * would be
 */
inline unsigned ipnet_mask(int cidr) {
        return (cidr == 0) ? 0 : (0xFFFFFFFF << (32 - cidr));
}
/**
 * Returns minimum IP address in the network.
 * This is the first address in the range, which is usually the network address.
 * Note that this is not always the first usable address in the range.
 * For example, in a /24 network, the first address is the network address,
 * which is not usable for hosts.
 * For /32 networks, the first address is the only address in the range.
 */
inline unsigned ipnet_min(ipnet_t *ipnet) {
        return ipnet->ip & ipnet_mask(ipnet->cidr);
}
/**
 * Returns the maximum IP address in the network.
 * This is the last address in the range, which is the broadcast address.
 * For /32 networks, the last address is the only address in the range.
 */
inline unsigned ipnet_max(ipnet_t *ipnet) {
        return ipnet->ip | ~ipnet_mask(ipnet->cidr);
}
/**
 * Returns the number of usable IP addresses in the network.
 * This is the total number of addresses in the range minus 2 (network and
 * broadcast). For /32 networks, this will be 0.
 */
inline unsigned ipnet_usable_count(ipnet_t *ipnet) {
        return ipnet->cidr == 32
                   ? 1
                   : (ipnet->cidr == 31 ? 2 : (1 << (32 - ipnet->cidr)) - 2);
}
/**
 * Return true if the IP address is in the network.
 */
inline int ipnet_contains_ip(ipnet_t *ipnet, unsigned ip) {
        return (ip & ipnet_mask(ipnet->cidr)) == ipnet_min(ipnet);
}
/**
 * Return true if the second network is contained in the first network.
 * This means that the second network is a subset of the first network.
 * For example,
 */
inline int ipnet_contains_ipnet(ipnet_t *ipnet, ipnet_t *ipnet2) {
        return (ipnet->ip == ipnet2->ip) && (ipnet->cidr <= ipnet2->cidr);
}
/**
 * Parse ip address and CIDR from string.
 * The string should be in the format "ip/cidr", where ip is a 32-bit
 * If subnet is /32, CIDR is optional.
 * The function will return 0 on failure, 1 on success.
 */
int ipnet_parse(ipnet_t *ipnet, const char *str);
/**
 * Convert ip address and CIDR to string.
 */
int ipnet_to_str(ipnet_t *ipnet, char *buf, size_t len);

#endif
