#ifndef ipnet_h
#define ipnet_h

typedef struct ipnet {
    unsigned ip;
    unsigned cidr;
    struct ipnet *next;
    struct ipnet *prev;
} ipnet_t;

#endif