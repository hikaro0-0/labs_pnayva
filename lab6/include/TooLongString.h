#pragma once
#ifndef TOOLONGSTRING_H
#define TOOLONGSTRING_H

#include <exception>

class TooLongString : public std::exception {
    const char* msg;
public:
    explicit TooLongString(const char* m);
    const char* what() const noexcept override;
};

#endif