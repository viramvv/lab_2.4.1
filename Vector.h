#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

const int MAX_CAPACITY = 100; // Максимальний розмір масиву

class Vector {
private:
    int* data;       // Вказівник на динамічний масив чисел
    int size_val;    // Поле size (максимальна місткість об'єкта)
    int count_val;   // Поле count (поточна кількість елементів)

public:
    // --- Конструктори ---
    Vector();                                  // Без аргументів
    Vector(int s);                             // Ініціалізації (задає size)
    Vector(const Vector& other);               // Копіювання (Deep Copy)
    Vector(const std::string& str);            // Ініціалізації рядком

    ~Vector(); // Деструктор (обов'язковий для динамічної пам'яті)

    // --- Методи доступу (Getters/Setters) ---
    int size() const { return size_val; }      // Метод size() за умовою
    int count() const { return count_val; }
    void setElement(int index, int value);     // Контроль коректності
    int getElement(int index) const;

    // --- Специфічні операції (Варіант 14) ---
    int calculateNorm() const;                 // Модуль різниці max та min

    // --- Перевантаження операторів (Методи) ---
    Vector& operator=(const Vector& other);    // Присвоєння
    int& operator[](int index);                // Індексування
    operator std::string() const;              // Приведення типу до string

    // Інкременти/Декременти (для поля count_val)
    Vector& operator++();    // Префіксний ++
    Vector operator++(int);  // Постфіксний ++
    Vector& operator--();    // Префіксний --
    Vector operator--(int);  // Постфіксний --

    Vector operator*(int scalar) const;        // Множення на скаляр

    // --- Дружні функції (Зовнішні) ---
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);

    // 6 операторів порівняння (як у вашому Money)
    friend bool operator==(const Vector& v1, const Vector& v2);
    friend bool operator!=(const Vector& v1, const Vector& v2);
    friend bool operator>(const Vector& v1, const Vector& v2);
    friend bool operator<(const Vector& v1, const Vector& v2);
    friend bool operator>=(const Vector& v1, const Vector& v2);
    friend bool operator<=(const Vector& v1, const Vector& v2);
};

#endif