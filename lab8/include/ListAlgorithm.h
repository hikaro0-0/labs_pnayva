#ifndef LISTALGORITHM_H
#define LISTALGORITHM_H

#include "container.h"
#include <iostream>
#include <algorithm>

template<typename T>
class ListAlgorithm {
public:
    static typename std::list<T>::iterator search(Container<T>& container, const T& value);
    static void sort(Container<T>& container);
    static void print(const Container<T>& container);

private:
    static std::list<T> quickSort(std::list<T> lst);
};

#include "ListAlgorithm.cpp"

#endif