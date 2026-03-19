#include <gtest/gtest.h>
#include "Vector.h"
#include <string>

// Тест конструкторів та початкових значень
TEST(VectorTest, ConstructorTest) {
    Vector v(5);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.count(), 0);
}

// Тест ініціалізації рядком
TEST(VectorTest, StringConstructorTest) {
    Vector v("10 20 30");
    EXPECT_EQ(v.count(), 3);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[2], 30);
}

// Тест інкременту (зміна поля count)
TEST(VectorTest, IncrementTest) {
    Vector v(10);
    ++v;
    EXPECT_EQ(v.count(), 1);
    v++;
    EXPECT_EQ(v.count(), 2);
}

// Тест норми (|max - min|)
TEST(VectorTest, NormTest) {
    Vector v("5 15 10"); // max=15, min=5
    EXPECT_EQ(v.calculateNorm(), 10);
}

// Тест порівняння (6 операторів)
TEST(VectorTest, ComparisonTest) {
    Vector v1("1 2 3");
    Vector v2("1 2 3");
    Vector v3("10 20");

    EXPECT_TRUE(v1 == v2);      // Рівність
    EXPECT_FALSE(v1 != v2);     // Нерівність
    EXPECT_TRUE(v3 > v1);       // Порівняння за сумою (30 > 6)
    EXPECT_TRUE(v1 < v3);
    EXPECT_TRUE(v3 >= v1);
    EXPECT_TRUE(v1 <= v2);
}

// Тест множення на скаляр
TEST(VectorTest, MultiplicationTest) {
    Vector v("2 4");
    Vector res = v * 2;
    EXPECT_EQ(res[0], 4);
    EXPECT_EQ(res[1], 8);
}

// Тест приведення до рядка
TEST(VectorTest, StringCastTest) {
    Vector v("1 2");
    std::string s = (std::string)v;
    EXPECT_TRUE(s.find("1") != std::string::npos);
}