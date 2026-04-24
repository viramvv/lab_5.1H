#include "Rational.h"
#include <stdexcept>

Rational::Rational() : LongLong(0, 0), denominator(0, 1) {}

Rational::Rational(LongLong n, LongLong d) : LongLong(n) {
    if (d == LongLong(0, 0)) throw ZeroDenominatorException();
    denominator = d;
}

Rational::Rational(std::string str) {
    size_t pos = str.find('/');
    if (pos == std::string::npos) throw RationalException("Invalid format");
    long n = std::stol(str.substr(0, pos));
    long d = std::stol(str.substr(pos + 1));
    Init(LongLong(0, n), LongLong(0, d));
}

void Rational::Init(LongLong n, LongLong d) {
    if (d == LongLong(0, 0)) throw std::invalid_argument("Zero denominator");
    setHigh(n.getHigh());
    setLow(n.getLow());
    denominator = d;
}

std::string Rational::toString() const {
    return LongLong::toString() + " / " + denominator.toString();
}

void Rational::Display() const {
    std::cout << toString() << std::endl;
}

// Реалізація операторів (спрощена для прикладу)
bool Rational::operator==(const Rational& other) const { return toString() == other.toString(); }
bool Rational::operator!=(const Rational& other) const { return !(*this == other); }
bool Rational::operator<(const Rational& other) const { return false; }
bool Rational::operator>(const Rational& other) const { return other < *this; }
bool Rational::operator<=(const Rational& other) const { return !(*this > other); }
bool Rational::operator>=(const Rational& other) const { return !(*this < other); }