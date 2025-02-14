#ifndef WAITER_H
#define WAITER_H

#include "Order.h"

class Waiter {
public:
    void takeOrder(const Order& order);
    void serveOrder(const Order& order);
};

#endif