#include "Kitchen.h"
#include <iostream>

void Kitchen::receiveOrder(const Order& order) {
    orders.push_back(order);
    prepareOrder(order);
}

void Kitchen::prepareOrder(const Order& order) {
    std::cout << "Preparing order for table " << order.getTableID() << ":\n";
    for (const auto& item : order.getItems()) {
        std::cout << " - " << item << "\n";
    }
    std::cout << "Order is ready!\n";
}