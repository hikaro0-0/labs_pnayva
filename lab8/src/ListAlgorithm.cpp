#ifndef LISTALGORITHM_CPP
#define LISTALGORITHM_CPP

#include "ListAlgorithm.h"
#include <algorithm>
#include <ranges>

template<typename T>
typename std::list<T>::iterator ListAlgorithm<T>::search(Container<T>& container, const T& value) {
    return std::ranges::find(container, value);
}

template<typename T>
void ListAlgorithm<T>::sort(Container<T>& container) {
    if (container.size() <= 1) return;

    std::list<T> tempList(container.begin(), container.end());
    tempList = quickSort(tempList);

    container.clear();
    for (const auto& item : tempList) {
        container.add(item);
    }
}

template<typename T>
void ListAlgorithm<T>::print(const Container<T>& container) {
    if (container.empty()) {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    std::cout << "Содержимое списка: ";
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::list<T> ListAlgorithm<T>::quickSort(std::list<T> lst) {
    if (lst.size() <= 1) {
        return lst;
    }

    T pivot = lst.front();
    lst.pop_front();
    
    std::list<T> less;
    std::list<T> equal;
    std::list<T> greater;
    equal.push_back(pivot);

    for (const auto& item : lst) {
        if (item < pivot) {
            less.push_back(item);
        }
        else if (item > pivot) {
            greater.push_back(item);
        }
        else {
            equal.push_back(item);
        }
    }

    less = quickSort(less);
    greater = quickSort(greater);

    std::list<T> result;
    result.splice(result.end(), less);
    result.splice(result.end(), equal);
    result.splice(result.end(), greater);

    return result;
}

#endif

