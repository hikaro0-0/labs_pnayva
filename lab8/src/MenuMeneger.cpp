#include "MenuMeneger.h"

int MenuManager::selectDataType() {
    int choice;
    std::cout << "\n=== ВЫБОР ТИПА ДАННЫХ ===" << std::endl;
    std::cout << "1. Целые числа" << std::endl;
    std::cout << "2. Строки" << std::endl;
    std::cout << "3. Вещественные числа" << std::endl;
    std::cout << "Выберите тип данных: ";
    std::cin >> choice;
    return choice;
}

void MenuManager::loadIntPreset() {
    intContainer.clear();
    intContainer.add(5);
    intContainer.add(2);
    intContainer.add(8);
    intContainer.add(1);
    intContainer.add(9);
    std::cout << "Загружен предустановленный набор для целых чисел" << std::endl;
}

void MenuManager::loadStringPreset() {
    stringContainer.clear();
    stringContainer.add("banana");
    stringContainer.add("apple");
    stringContainer.add("cherry");
    stringContainer.add("date");
    std::cout << "Загружен предустановленный набор для строк" << std::endl;
}

void MenuManager::loadDoublePreset() {
    doubleContainer.clear();
    doubleContainer.add(3.14);
    doubleContainer.add(2.71);
    doubleContainer.add(1.41);
    doubleContainer.add(1.61);
    std::cout << "Загружен предустановленный набор для вещественных чисел" << std::endl;
}

void MenuManager::loadPresetMenu() {
    int dataType = selectDataType();

    switch (dataType) {
    case 1: loadIntPreset(); break;
    case 2: loadStringPreset(); break;
    case 3: loadDoublePreset(); break;
    default: std::cout << "Неверный выбор типа данных!" << std::endl;
    }
}

void MenuManager::addCustomDataMenu() {
    int dataType = selectDataType();

    switch (dataType) {
    case 1: {
        int value;
        std::cout << "Введите целое число для добавления: ";
        std::cin >> value;
        intContainer.add(value);
        std::cout << "Число " << value << " добавлено в список." << std::endl;
        break;
    }
    case 2: {
        std::string value;
        std::cout << "Введите строку для добавления: ";
        std::cin.ignore();
        std::getline(std::cin, value);
        stringContainer.add(value);
        std::cout << "Строка \"" << value << "\" добавлена в список." << std::endl;
        break;
    }
    case 3: {
        double value;
        std::cout << "Введите вещественное число для добавления: ";
        std::cin >> value;
        doubleContainer.add(value);
        std::cout << "Число " << value << " добавлено в список." << std::endl;
        break;
    }
    default:
        std::cout << "Неверный выбор типа данных!" << std::endl;
    }
}

void MenuManager::operationsMenu() {
    int dataType = selectDataType();

    std::cout << "\n=== ОПЕРАЦИИ ===" << std::endl;
    std::cout << "1. Показать содержимое" << std::endl;
    std::cout << "2. Отсортировать" << std::endl;
    std::cout << "3. Найти элемент" << std::endl;
    std::cout << "4. Очистить" << std::endl;
    std::cout << "Выберите операцию: ";

    int operation;
    std::cin >> operation;

    switch (dataType) {
    case 1: performIntOperation(operation); break;
    case 2: performStringOperation(operation); break;
    case 3: performDoubleOperation(operation); break;
    default: std::cout << "Неверный выбор типа данных!" << std::endl;
    }
}

void MenuManager::performIntOperation(int operation) {
    switch (operation) {
    case 1:
        std::cout << "Целые числа: ";
        ListAlgorithm<int>::print(intContainer);
        break;
    case 2:
        ListAlgorithm<int>::sort(intContainer);
        std::cout << "Список целых чисел отсортирован!" << std::endl;
        break;
    case 3: {
        int value;
        std::cout << "Введите число для поиска: ";
        std::cin >> value;
        if (auto found = ListAlgorithm<int>::search(intContainer, value); found != intContainer.end()) {
            std::cout << "Элемент " << value << " найден!" << std::endl;
        }
        else {
            std::cout << "Элемент " << value << " не найден." << std::endl;
        }
        break;
    }
    case 4:
        intContainer.clear();
        std::cout << "Список целых чисел очищен!" << std::endl;
        break;
    default:
        std::cout << "Неверная операция!" << std::endl;
    }
}

void MenuManager::performStringOperation(int operation) {
    switch (operation) {
    case 1:
        std::cout << "Строки: ";
        ListAlgorithm<std::string>::print(stringContainer);
        break;
    case 2:
        ListAlgorithm<std::string>::sort(stringContainer);
        std::cout << "Список строк отсортирован!" << std::endl;
        break;
    case 3: {
        std::string value;
        std::cout << "Введите строку для поиска: ";
        std::cin.ignore();
        std::getline(std::cin, value);
        if (auto found = ListAlgorithm<std::string>::search(stringContainer, value); found != stringContainer.end()) {
            std::cout << "Строка \"" << value << "\" найдена!" << std::endl;
        }
        else {
            std::cout << "Строка \"" << value << "\" не найдена." << std::endl;
        }
        break;
    }
    case 4:
        stringContainer.clear();
        std::cout << "Список строк очищен!" << std::endl;
        break;
    default:
        std::cout << "Неверная операция!" << std::endl;
    }
}

void MenuManager::performDoubleOperation(int operation) {
    switch (operation) {
    case 1:
        std::cout << "Вещественные числа: ";
        ListAlgorithm<double>::print(doubleContainer);
        break;
    case 2:
        ListAlgorithm<double>::sort(doubleContainer);
        std::cout << "Список вещественных чисел отсортирован!" << std::endl;
        break;
    case 3: {
        double value;
        std::cout << "Введите число для поиска: ";
        std::cin >> value;
        if (auto found = ListAlgorithm<double>::search(doubleContainer, value); found != doubleContainer.end()) {
            std::cout << "Элемент " << value << " найден!" << std::endl;
        }
        else {
            std::cout << "Элемент " << value << " не найден." << std::endl;
        }
        break;
    }
    case 4:
        doubleContainer.clear();
        std::cout << "Список вещественных чисел очищен!" << std::endl;
        break;
    default:
        std::cout << "Неверная операция!" << std::endl;
    }
}

void MenuManager::showAllContainers() const {
    std::cout << "\n=== ВСЕ КОНТЕЙНЕРЫ ===" << std::endl;
    std::cout << "Целые числа: ";
    ListAlgorithm<int>::print(intContainer);
    std::cout << "Строки: ";
    ListAlgorithm<std::string>::print(stringContainer);
    std::cout << "Вещественные числа: ";
    ListAlgorithm<double>::print(doubleContainer);
}

void MenuManager::showMenu() {
    int choice;

    do {
        std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
        std::cout << "1. Загрузить предустановленные данные" << std::endl;
        std::cout << "2. Добавить пользовательские данные" << std::endl;
        std::cout << "3. Операции с данными" << std::endl;
        std::cout << "4. Показать все контейнеры" << std::endl;
        std::cout << "5. Отсортировать все контейнеры" << std::endl;
        std::cout << "6. Очистить все контейнеры" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: loadPresetMenu(); break;
        case 2: addCustomDataMenu(); break;
        case 3: operationsMenu(); break;
        case 4: showAllContainers(); break;
        case 5:
            ListAlgorithm<int>::sort(intContainer);
            ListAlgorithm<std::string>::sort(stringContainer);
            ListAlgorithm<double>::sort(doubleContainer);
            std::cout << "Все контейнеры отсортированы!" << std::endl;
            break;
        case 6:
            intContainer.clear();
            stringContainer.clear();
            doubleContainer.clear();
            std::cout << "Все контейнеры очищены!" << std::endl;
            break;
        case 0: std::cout << "Выход из программы..." << std::endl; break;
        default: std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    } while (choice != 0);
}