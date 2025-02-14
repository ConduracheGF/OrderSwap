#include "Order.h"

Order::Order(int tableID) : tableID(tableID) {}

void Order::addItem(const std::string& item) {
    items.push_back(item);
}

std::vector<std::string> Order::getItems() const {
    return items;
}

int Order::getTableID() const {
    return tableID;
}