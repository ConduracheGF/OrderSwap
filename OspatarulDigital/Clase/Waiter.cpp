#include "Waiter.h"
#include <iostream>

void Waiter::takeOrder(const Order& order) {
    std::cout << "Waiter took order from table " << order.getTableID() << ".\n";
}

void Waiter::serveOrder(const Order& order) {
    std::cout << "Waiter is serving order to table " << order.getTableID() << ".\n";
}