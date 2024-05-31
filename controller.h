#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "view.h"
#include <string>

class Controller {
public:
    Controller(Model& model, View& view);
    void displayRecords() const;
    void addRecord();
    void saveRecords() const;
    void loadRecords();
    void deleteRecord();

private:
    Model& model;
    View& view;
};

Controller::Controller(Model& model, View& view) : model(model), view(view) {}

void Controller::displayRecords() const {
    view.displayRecords(model.getRecords());
}

void Controller::addRecord() {
    std::string date, customer, product;
    int quantity;
    
    std::cout << "Введите дату (Год-Месяц-День): ";
    std::cin >> date;
    std::cout << "Введите имя заказчика: ";
    std::cin >> customer;
    std::cout << "Введите название продукта: ";
    std::cin >> product;
    std::cout << "Введите количество: ";
    std::cin >> quantity;

    Order order(0, product, quantity);  
    Record record(date, customer, order);
    model.addRecord(record);
}

void Controller::saveRecords() const {
    model.saveToFile();
}

void Controller::loadRecords() {
    model.loadFromFile();
}

void Controller::deleteRecord() {
    std::string customer;
    std::cout << "Введите имя заказчика для удаления: ";
    std::cin >> customer;
    model.removeRecord(customer);
}

#endif 
