#include <iostream>
#include "model.h"
#include "view.h"
#include <windows.h>
#include "controller.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Model model;
    View view;
    Controller controller(model, view);

    int choice = -1;
    while (choice != 0) {
        view.displayMenu();
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            controller.displayRecords();
            break;
        case 2:
            controller.addRecord();
            break;
        case 3:
            controller.saveRecords();
            break;
        case 4:
            controller.loadRecords();
            break;
        case 5:
            controller.deleteRecord();
            break;
        case 0:
            std::cout << "Выход\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
