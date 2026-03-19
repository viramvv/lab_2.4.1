#include "Vector.h"
#include <sstream>
#include <cmath>
#include <algorithm>

// Конструктори
Vector::Vector() : size_val(10), count_val(0) {
    data = new int[size_val]{0};
}

Vector::Vector(int s) : count_val(0) {
    size_val = (s > 0 && s <= MAX_CAPACITY) ? s : 10;
    data = new int[size_val]{0};
}

Vector::Vector(const Vector& other) {
    size_val = other.size_val;
    count_val = other.count_val;
    data = new int[size_val];
    for (int i = 0; i < size_val; i++) data[i] = other.data[i];
}

Vector::Vector(const std::string& str) : size_val(10), count_val(0) {
    data = new int[size_val];
    std::stringstream ss(str);
    int val;
    while (ss >> val && count_val < size_val) {
        data[count_val++] = val;
    }
}

Vector::~Vector() { delete[] data; }

// Сеттер з контролем (умова: неможливо обійти перевірку)
void Vector::setElement(int index, int value) {
    if (index >= 0 && index < size_val) {
        data[index] = value;
        if (index >= count_val) count_val = index + 1;
    } else {
        std::cerr << "Error: Index out of bounds!" << std::endl;
    }
}

int Vector::getElement(int index) const {
    return (index >= 0 && index < count_val) ? data[index] : 0;
}

// Інкременти/Декременти (змінюють кількість активних елементів count)
Vector& Vector::operator++() { if (count_val < size_val) count_val++; return *this; }
Vector Vector::operator++(int) { Vector temp(*this); ++(*this); return temp; }
Vector& Vector::operator--() { if (count_val > 0) count_val--; return *this; }
Vector Vector::operator--(int) { Vector temp(*this); --(*this); return temp; }

//Норма вектора
int Vector::calculateNorm() const {
    if (count_val == 0) return 0;
    int min_v = data[0], max_v = data[0];
    for (int i = 1; i < count_val; i++) {
        if (data[i] < min_v) min_v = data[i];
        if (data[i] > max_v) max_v = data[i];
    }
    return std::abs(max_v - min_v);
}

// Множення на скаляр
Vector Vector::operator*(int scalar) const {
    Vector res(*this);
    for (int i = 0; i < res.count_val; i++) res.data[i] *= scalar;
    return res;
}

// Присвоєння (глибоке копіювання)
Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] data;
    size_val = other.size_val;
    count_val = other.count_val;
    data = new int[size_val];
    for (int i = 0; i < size_val; i++) data[i] = other.data[i];
    return *this;
}

// Індексування
int& Vector::operator[](int index) {
    return data[index]; // Для демонстрації без перевірок, або додати if
}

// ПРИВЕДЕННЯ ДО РЯДКА
Vector::operator std::string() const {
    std::string s = "Vector [count=" + std::to_string(count_val) + "]: { ";
    for (int i = 0; i < count_val; i++) s += std::to_string(data[i]) + " ";
    s += "}";
    return s;
}

// ВВІД
std::istream& operator>>(std::istream& in, Vector& v) {
    for (int i = 0; i < v.size_val; i++) {
        int temp;
        std::cout << "Element [" << i << "]: ";
        in >> temp;
        v.setElement(i, temp);
    }
    return in;
}

// ВИВІД
std::ostream& operator<<(std::ostream& out, const Vector& v) {
    out << (std::string)v;
    return out;
}

// --- ПОРІВНЯННЯ ---
// Рівність: поелементна
bool operator==(const Vector& v1, const Vector& v2) {
    if (v1.count_val != v2.count_val) return false;
    for (int i = 0; i < v1.count_val; i++) 
        if (v1.data[i] != v2.data[i]) return false;
    return true;
}

bool operator!=(const Vector& v1, const Vector& v2) { return !(v1 == v2); }

// Порівняння за сумою елементів (вага вектора)
long getSum(const Vector& v) {
    long s = 0;
    for (int i = 0; i < v.count(); i++) s += v.getElement(i);
    return s;
}

bool operator>(const Vector& v1, const Vector& v2) { return getSum(v1) > getSum(v2); }
bool operator<(const Vector& v1, const Vector& v2) { return getSum(v1) < getSum(v2); }
bool operator>=(const Vector& v1, const Vector& v2) { return !(v1 < v2); }
bool operator<=(const Vector& v1, const Vector& v2) { return !(v1 > v2); }