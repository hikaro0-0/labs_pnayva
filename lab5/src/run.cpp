#include "SingleLinkedList.h"

int run() {
    system("chcp 1251");
    setlocale(0, "rus");
    SingleLinkedList<std::string> list;
    list.input();
    std::cout << "Ваш список: " << std::endl;
    list.print();

    return 0;
}