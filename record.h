#ifndef RECORD_H
#define RECORD_H

#include "order.h"
#include <string>

class Record {
public:
    Record(const std::string& date, const std::string& customer, const Order& order);

    std::string getDate() const;
    std::string getCustomer() const;
    const Order& getOrder() const;

private:
    std::string date;
    std::string customer;
    Order order;
};

Record::Record(const std::string& date, const std::string& customer, const Order& order)
    : date(date), customer(customer), order(order) {}

std::string Record::getDate() const {
    return date;
}

std::string Record::getCustomer() const {
    return customer;
}

const Order& Record::getOrder() const {
    return order;
}

#endif 
