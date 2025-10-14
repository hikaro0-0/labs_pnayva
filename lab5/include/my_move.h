#pragma once
#include <iostream>
template<typename T>
constexpr std::remove_reference_t<T>&& my_move(T&& arg) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(arg);
}

template<typename T> struct my_remove_reference { typedef T type; };
template<typename T> struct my_remove_reference<T&> { typedef T type; };
template<typename T> struct my_remove_reference<T&&> { typedef T type; };

// Собственная реализация move
template<typename T>
constexpr typename my_remove_reference<T>::type&& my_move(T&& arg) noexcept {
    return static_cast<typename my_remove_reference<T>::type&&>(arg);
}

// Собственная реализация forward
template<typename T>
constexpr T&& my_forward(typename my_remove_reference<T>::type& arg) noexcept {
    return static_cast<T&&>(arg);
}

template<typename T>
constexpr T&& my_forward(typename my_remove_reference<T>::type&& arg) noexcept {
    static_assert(!std::is_lvalue_reference<T>::value, "Cannot forward rvalue as lvalue");
    return static_cast<T&&>(arg);
}

// Вспомогательные трейты для проверки типов
template<typename T> struct my_is_lvalue_reference { static constexpr bool value = false; };
template<typename T> struct my_is_lvalue_reference<T&> { static constexpr bool value = true; };