#include "TooLongString.h"

TooLongString::TooLongString(const char* m) : msg(m) {}

const char* TooLongString::what() const noexcept {
    return msg;
}