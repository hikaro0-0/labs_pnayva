#pragma once
#include <iostream>
template<typename T>
constexpr typename std::remove_reference<T>::type&& my_move(T&& arg) noexcept {
    return static_cast<typename std::remove_reference<T>::type&&>(arg);
}