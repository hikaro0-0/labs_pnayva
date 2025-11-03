#include "run.h"

void processStrings() {
    try {
        std::cout << "=== Программа конкатенации строк ===" << std::endl;

        MyString s1 = MyString::inputMsg("Введите первую строку: ");
        MyString s2 = MyString::inputMsg("Введите вторую строку: ");

        std::cout << "Первая строка: \"" << s1 << "\" (длина: " << s1.size() << ")" << std::endl;
        std::cout << "Вторая строка: \"" << s2 << "\" (длина: " << s2.size() << ")" << std::endl;

        MyString s3 = s1 + s2;
        std::cout << "Результат конкатенации: \"" << s3 << "\" (длина: " << s3.size() << ")" << std::endl;
    }
    catch (const TooLongString& e) {
        std::cerr << e.what() << std::endl;
    }
}
