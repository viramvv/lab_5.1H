#pragma once
#include "LongLong.h"
#include "Exceptions.h"
#include <string>

class Rational : public LongLong {
private:
    LongLong denominator;
public:
    Rational();
    // Виправляємо типи на LongLong (без &), щоб збігалося з вашим .cpp
    Rational(LongLong n, LongLong d);
    // Додаємо оголошення, бо в .cpp воно є, а тут не було
    Rational(std::string str);

    void Init(LongLong n, LongLong d);
    void Read();
    void Display() const;
    std::string toString() const;

    // Оператори порівняння
    bool operator == (const Rational& other) const;
    bool operator != (const Rational& other) const;
    bool operator <  (const Rational& other) const;
    bool operator >  (const Rational& other) const;
    bool operator <= (const Rational& other) const;
    bool operator >= (const Rational& other) const;
};