#ifndef MODEL_H
#define MODEL_H

#include "multiplTree.h"
#include "record.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream> 

class Model {
public:
    void addRecord(const Record& record);
    void saveToFile() const;
    void loadFromFile();
    void removeRecord(const std::string& customer);
    const MultiplTree& getRecords() const;

private:
    MultiplTree records;
};



void Model::addRecord(const Record& record) {
    auto customerNode = std::make_shared<MultiplTree>(record.getCustomer());
    auto dateNode = std::make_shared<MultiplTree>("Date");
    dateNode->setValue(record.getDate());
    auto productNode = std::make_shared<MultiplTree>("Product");
    productNode->setValue(record.getOrder().getProduct());
    auto quantityNode = std::make_shared<MultiplTree>("Quantity");
    quantityNode->setValue(record.getOrder().getQuantity());


    customerNode->addSub(dateNode);
    customerNode->addSub(productNode);
    customerNode->addSub(quantityNode);

    records.addSub(customerNode);
}

void Model::saveToFile() const {
    std::ofstream file("records.xml");
    if (file.is_open()) {
        file << "<records>\n";
        
        for (size_t i = 0; i < records.getCountSub(); ++i) {
            auto customerNode = records.getSub(i);
            file << "    <record>\n";
            file << "        <customer>" << customerNode->getName() << "</customer>\n";
            for (size_t j = 0; j < customerNode->getCountSub(); ++j) {
                auto detailNode = customerNode->getSub(j);
                file << "        <" << detailNode->getName() << ">" << detailNode->getValue() << "</" << detailNode->getName() << ">\n";
            }
            file << "    </record>\n";
        }
        file << "</records>\n";
        file.close();
        std::cout << "Заказы сохранены в файл\n";
    } else {
        std::cout << "Ошибка: Невозможно сохранить заказы\n";
    }
}


void Model::loadFromFile() {
    std::ifstream file("records.xml");
    if (file.is_open()) {
        records = MultiplTree("Root"); //Очистить текущие записи
        std::string line, tag;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> tag;
            if (tag == "<record>") {
                std::string date, customer, product;
                int quantity;
                std::getline(file, line); 
                customer = line.substr(line.find(">") + 1);
                customer = customer.substr(0, customer.find("<"));

                std::getline(file, line); 
                date = line.substr(line.find(">") + 1);
                date = date.substr(0, date.find("<"));

                std::getline(file, line); 
                product = line.substr(line.find(">") + 1);
                product = product.substr(0, product.find("<"));

                std::getline(file, line); 
                std::string quantityStr = line.substr(line.find(">") + 1);
                quantityStr = quantityStr.substr(0, quantityStr.find("<"));
                quantity = std::stoi(quantityStr);

                Order order(0, product, quantity);
                Record record(date, customer, order);
                addRecord(record);
            }
        }
        file.close();
        std::cout << "Заказы загружены из файла\n";
    } else {
        std::cout << "Ошибка: Невозможно загрузить заказы\n";
    }
}

void Model::removeRecord(const std::string& customer) {
    records.removeSub(customer);
}

const MultiplTree& Model::getRecords() const {
    return records;
}

#endif 
