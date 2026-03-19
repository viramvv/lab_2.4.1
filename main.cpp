#include <iostream>
#include "Vector.h"

// Демонстрація вирівнювання пам'яті
#pragma pack(push, 1)
struct PackedVector {
    int* d;
    int s;
    int c;
};
#pragma pack(pop)

int main() {
    // 1. Вивід розмірів класу
    std::cout << "--- Memory Sizes ---" << std::endl;
    std::cout << "Normal class size: " << sizeof(Vector) << " bytes" << std::endl;
    std::cout << "Packed (pragma pack 1) size: " << sizeof(PackedVector) << " bytes" << std::endl;
    std::cout << "--------------------" << std::endl;

    // 2. Різні способи створення
    Vector v1(3);               // Конструктор ініціалізації
    Vector v2("10 20 30 40");   // З рядка
    Vector v3 = v2;             // Копіювання

    // 3. Робота операторів
    std::cout << "V2 initial: " << v2 << std::endl;
    v2++; // інкремент (збільшить count)
    std::cout << "V2 after ++: " << v2 << std::endl;

    Vector v4 = v1 * 5; // множення на скаляр

    // 4. Порівняння
    if (v2 != v1) std::cout << "V2 and V1 are different" << std::endl;
    if (v2 > v1) std::cout << "V2 is greater than V1 (by sum)" << std::endl;

    // 5. Специфічне завдання (Норма)
    std::cout << "Norm of V2: " << v2.calculateNorm() << std::endl;

    // 6. Масив об'єктів
    Vector arr[2] = { Vector(2), Vector("5 5") };
    std::cout << "Array element 1: " << arr[1] << std::endl;

    return 0;
}