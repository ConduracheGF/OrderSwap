#ifndef KITCHEN_H
#define KITCHEN_H

#include "Order.h"
#include <vector>

class Kitchen {
private:
    std::vector<Order> orders;

public:
    void receiveOrder(const Order& order);
    void prepareOrder(const Order& order);
};

#endif