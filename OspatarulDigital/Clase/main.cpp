#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Order.h"
#include "Kitchen.h"
#include "Waiter.h"

std::pair<int, std::vector<std::string>> read_order_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> items;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Eroare: Nu s-a putut deschide fișierul " << filename << "\n";
        return std::make_pair(0, items);
    }

    // Citim ID-ul mesei (prima linie)
    std::getline(file, line);
    int tableID = 0;
    size_t colonPos = line.find(":");
    if (colonPos != std::string::npos) {
        // Dacă `:` există, extragem `tableID`
        tableID = std::stoi(line.substr(colonPos + 2));
    } else {
        std::cerr << "Eroare: Format invalid în fișierul de comandă (lipsă ':')\n";
    }

    // Citim elementele comenzii
    while (std::getline(file, line)) {
        items.push_back(line);
    }

    file.close();
    return std::make_pair(tableID, items);
}

int main() {
    // Citim comanda din fișier
    auto [tableID, items] = read_order_from_file("shared/order.txt");  // Extragem tableID și items

    // Creăm comanda
    Order order(tableID);
    for (const auto& item : items) {
        order.addItem(item);
    }

    // Procesăm comanda
    Kitchen kitchen;
    Waiter waiter;

    waiter.takeOrder(order);
    kitchen.receiveOrder(order);
    waiter.serveOrder(order);

    return 0;
}