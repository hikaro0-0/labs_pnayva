#ifndef CONTAINER_CPP
#define CONTAINER_CPP

#include "Container.h"

template<typename T>
void Container<T>::add(const T& value) {
    data.push_back(value);
}

template<typename T>
void Container<T>::remove(const T& value) {
    data.remove(value);
}

template<typename T>
typename std::list<T>::iterator Container<T>::begin() {
    return data.begin();
}

template<typename T>
typename std::list<T>::iterator Container<T>::end() {
    return data.end();
}

template<typename T>
typename std::list<T>::const_iterator Container<T>::begin() const {
    return data.begin();
}

template<typename T>
typename std::list<T>::const_iterator Container<T>::end() const {
    return data.end();
}

template<typename T>
size_t Container<T>::size() const {
    return data.size();
}

template<typename T>
bool Container<T>::empty() const {
    return data.empty();
}

template<typename T>
void Container<T>::clear() {
    data.clear();
}

#endif