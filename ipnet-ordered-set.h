#ifndef ipnet_ordered_set_h
#define ipnet_ordered_set_h

#include "ipnet.h"

typedef struct ipnet_ordered_set {
    struct ipnet *head;
    struct ipnet *tail;
    int count;
} ipnet_ordered_set_t;



#endif