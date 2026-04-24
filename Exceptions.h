#pragma once
#include <exception>
#include <string>

// Власний базовий виняток
class RationalException : public std::exception {
protected:
    std::string message;
public:
    RationalException(const std::string& msg);
    virtual const char* what() const noexcept override;
};

// Власний виняток-нащадок
class ZeroDenominatorException : public RationalException {
public:
    ZeroDenominatorException();
};