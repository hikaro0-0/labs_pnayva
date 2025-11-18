#ifndef CONTAINER_H
#define CONTAINER_H

#include <list>

template<typename T>
class Container {
private:
    std::list<T> data;

public:
    void add(const T& value);
    void remove(const T& value);

    typename std::list<T>::iterator begin();
    typename std::list<T>::iterator end();
    typename std::list<T>::const_iterator begin() const;
    typename std::list<T>::const_iterator end() const;

    size_t size() const;
    bool empty() const;
    void clear();
};

#include "container.cpp"

#endif