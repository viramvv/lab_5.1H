cmake_minimum_required(VERSION 3.10)
project(RationalProject)

# Встановлюємо стандарт, який частіше пробачає дрібні розбіжності
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. ВИПРАВЛЕННЯ ПОМИЛКИ 404: Використовуємо стабільне посилання на версію 1.14.0
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Для уникнення конфліктів налаштувань
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Списки файлів
set(SOURCE_FILES
        LongLong.cpp
        Rational.cpp
)

# Основна програма
add_executable(RationalApp main.cpp ${SOURCE_FILES})

# Тести
add_executable(UnitTest UnitTest.cpp ${SOURCE_FILES})
target_link_libraries(UnitTest GTest::gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND UnitTest)