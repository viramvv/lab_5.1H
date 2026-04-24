#pragma once
#include <iostream>
#include <string>

class LongLong {
private:
    long high;
    unsigned long low;

public:
    LongLong(long h = 0, unsigned long l = 0) : high(h), low(l) {}
    LongLong(const LongLong& other) : high(other.high), low(other.low) {}

    long getHigh() const { return high; }
    unsigned long getLow() const { return low; }
    void setHigh(long h) { high = h; }
    void setLow(unsigned long l) { low = l; }

    void Init(long h, unsigned long l);
    void Read();
    void Display() const;
    std::string toString() const;

    LongLong& operator++();
    LongLong operator++(int);
    LongLong& operator--();
    LongLong operator--(int);

    friend bool operator==(const LongLong& a, const LongLong& b);
    friend bool operator!=(const LongLong& a, const LongLong& b);
    friend bool operator<(const LongLong& a, const LongLong& b);
    friend bool operator>(const LongLong& a, const LongLong& b);
    friend bool operator<=(const LongLong& a, const LongLong& b);
    friend bool operator>=(const LongLong& a, const LongLong& b);


    friend LongLong operator+(const LongLong& a, const LongLong& b);
    friend LongLong operator/(const LongLong& a, const LongLong& b);

    operator std::string() const { return toString(); }
};