#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

class Order {
private:
    int tableID;
    std::vector<std::string> items;

public:
    Order(int tableID);
    void addItem(const std::string& item);
    std::vector<std::string> getItems() const;
    int getTableID() const;
};

#endif