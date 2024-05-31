#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
    Order(int orderId, const std::string& product, int quantity);

    int getOrderId() const;
    std::string getProduct() const;
    int getQuantity() const;


private:
    int orderId;
    std::string product;
    int quantity;
};



Order::Order(int orderId, const std::string& product, int quantity)
    : orderId(orderId), product(product), quantity(quantity) {}

int Order::getOrderId() const {
    return orderId;
}

std::string Order::getProduct() const {
    return product;
}

int Order::getQuantity() const {
    return quantity;
}

#endif 
