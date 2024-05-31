#ifndef VIEW_H
#define VIEW_H

#include "multiplTree.h"
#include <iostream>

class View {
public:
    void displayRecords(const MultiplTree& records) const;
    void displayMenu() const;
};

void View::displayRecords(const MultiplTree& records) const {
    std::cout << "Список заказов:\n";
    for (size_t i = 0; i < records.getCountSub(); ++i) {
        auto customerNode = records.getSub(i);
        if (customerNode) {
            std::cout << "Заказчик: " << customerNode->getName() << "\n";
            for (size_t j = 0; j < customerNode->getCountSub(); ++j) {
                auto detailNode = customerNode->getSub(j);
                if (detailNode) {
                    std::cout << "  " << detailNode->getName() << ": " << detailNode->getValue() << "\n";
                }
            }
            std::cout << "-----------------------\n";
        }
    }
}

void View::displayMenu() const {
    std::cout << "1. Вывести список заказов\n";
    std::cout << "2. Добавить новый заказ\n";
    std::cout << "3. Сохранить заказы\n";
    std::cout << "4. Загрузить заказы\n";
    std::cout << "5. Удалить заказ\n";
    std::cout << "0. Выход\n";
}

#endif 
