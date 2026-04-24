#include <iostream>
#include <stdexcept>
#include "Rational.h"
#include "Exceptions.h"

using namespace std;

// 1. ПЕРЕДАЧА ЗА ЗНАЧЕННЯМ (Value)
// Створюється копія об'єкта. Тут працює конструктор копіювання.
void ShowByValue(Rational r) {
    cout << "Inside ShowByValue: " << r.toString() << endl;
}

// 2. ПЕРЕДАЧА ЗА ПОСИЛАННЯМ (Reference)
// Копія не створюється. Працюємо через константне посилання.
void ShowByRef(const Rational& r) {
    cout << "Inside ShowByRef: " << r.toString() << endl;
}

int main() {
    // --- ПЕРЕВІРКА РОЗМІРУ КЛАСУ ---
    cout << "Size of Rational (normal): " << sizeof(Rational) << " bytes" << endl;

    // Демонстрація розміру з вирівнюванням (імітація через структуру для наочності)
    #pragma pack(push, 1)
    struct RationalPacked {
        long h1; unsigned long l1; // Базовий LongLong (чисельник)
        long h2; unsigned long l2; // Поле LongLong (знаменник)
    };
    #pragma pack(pop)
    cout << "Size of Rational (packed): " << sizeof(RationalPacked) << " bytes" << endl;
    cout << "------------------------------------------" << endl;

    // 3. ПЕРЕДАЧА ЗА ВИНИТКОМ (Exception handling)
    try {
        cout << "Step 1: Normal initialization..." << endl;
        Rational r1(LongLong(0, 1), LongLong(0, 2)); // 1/2

        cout << "Testing 'By Value': ";
        ShowByValue(r1); // Передача за значенням

        cout << "Testing 'By Reference': ";
        ShowByRef(r1);   // Передача за посиланням

        cout << "\nStep 2: Testing Custom Exception (Child)..." << endl;
        // Спроба створити дріб із нульовим знаменником (викличе ZeroDenominatorException)
        Rational r_err(LongLong(0, 5), LongLong(0, 0));

    }
    // Перехоплення ЗА ВИНИТКОМ (за посиланням на об'єкт винятку)
    catch (const ZeroDenominatorException& e) {
        cerr << "Caught Specific (Child): " << e.what() << endl;
    }
    catch (const RationalException& e) {
        cerr << "Caught Base Custom: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Caught Standard Exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Caught General Standard: " << e.what() << endl;
    }

    cout << "\nStep 3: Testing Standard Exception via Init()..." << endl;
    try {
        Rational r2;
        r2.Init(LongLong(0, 10), LongLong(0, 0)); // Викличе std::invalid_argument
    }
    catch (const exception& e) {
        cerr << "Caught in Step 3: " << e.what() << endl;
    }

    return 0;
}