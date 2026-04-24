#include <gtest/gtest.h>
#include "Rational.h"
#include "Exceptions.h"

// 1. Тест на конструктор та виняток-нащадок
TEST(RationalExceptionTest, ThrowsZeroDenominator) {
    LongLong num(0, 5);
    LongLong den(0, 0);

    // Перевіряємо, чи кидається саме твій власний нащадок винятку
    EXPECT_THROW({
        Rational r(num, den);
    }, ZeroDenominatorException);
}

// 2. Тест на стандартний виняток у методі Init
TEST(RationalExceptionTest, ThrowsStandardInInit) {
    Rational r;
    LongLong num(0, 10);
    LongLong den(0, 0);

    // Перевіряємо, чи Init кидає std::invalid_argument (стандартний виняток)
    EXPECT_THROW({
        r.Init(num, den);
    }, std::invalid_argument);
}

// 3. Тест на базовий власний виняток (якщо він кидається)
TEST(RationalExceptionTest, CatchBaseException) {
    try {
        throw RationalException("Some general error");
    } catch (const RationalException& e) {
        EXPECT_STREQ(e.what(), "Rational Error: Some general error");
    }
}

// 4. Тест операцій порівняння (приклад для ==)
TEST(RationalLogicTest, EqualityOperator) {
    // Створюємо два однакових дроби 1/2
    Rational r1(LongLong(0, 1), LongLong(0, 2));
    Rational r2(LongLong(0, 1), LongLong(0, 2));

    EXPECT_TRUE(r1 == r2);
}

// 5. Тест toString
TEST(RationalLogicTest, ToStringFormat) {
    Rational r(LongLong(1, 10), LongLong(0, 5));
    // Перевіряємо формат виводу, який ти реалізував у LongLong
    EXPECT_FALSE(r.toString().empty());
}