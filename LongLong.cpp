#include "LongLong.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

RationalException::RationalException(const std::string& msg)
    : message("Rational Error: " + msg) {}

const char* RationalException::what() const noexcept {
    return message.c_str();
}

ZeroDenominatorException::ZeroDenominatorException()
    : RationalException("Denominator cannot be zero!") {}

// --- МЕТОДИ LONGLONG ---
void LongLong::Init(long h, unsigned long l) {
    high = h; low = l;
}

void LongLong::Read() {
    std::cout << "High: "; std::cin >> high;
    std::cout << "Low: "; std::cin >> low;
}

std::string LongLong::toString() const {
    return std::to_string(high) + ":" + std::to_string(low);
}

void LongLong::Display() const {
    std::cout << toString();
}

// 6 операцій порівняння
bool operator==(const LongLong& a, const LongLong& b) { return a.high == b.high && a.low == b.low; }
bool operator!=(const LongLong& a, const LongLong& b) { return !(a == b); }
bool operator<(const LongLong& a, const LongLong& b) {
    if (a.high < b.high) return true;
    if (a.high > b.high) return false;
    return a.low < b.low;
}
bool operator>(const LongLong& a, const LongLong& b) { return b < a; }
bool operator<=(const LongLong& a, const LongLong& b) { return !(a > b); }
bool operator>=(const LongLong& a, const LongLong& b) { return !(a < b); }

// Інкремент/Декремент
LongLong& LongLong::operator++() { if (++low == 0) high++; return *this; }
LongLong LongLong::operator++(int) { LongLong t(*this); ++(*this); return t; }
LongLong& LongLong::operator--() { if (low-- == 0) high--; return *this; }
LongLong LongLong::operator--(int) { LongLong t(*this); --(*this); return t; }