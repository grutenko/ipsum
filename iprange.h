#ifndef iprange_h
#define iprange_h

#include "ipnet-ordered-set.h"

/**
 * @brief Convert iprange into list of cidr list.
 * @param from unsigned
 * @param to unsigned
 * @param set ipnet_ordered_set_t
 * @return int Return count of created cidr nets
 */
int iprange2ipnetset(unsigned from, unsigned to, ipnet_ordered_set_t *set);

#endif
