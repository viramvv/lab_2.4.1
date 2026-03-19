cmake_minimum_required(VERSION 3.14)
project(VectorProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Підключення Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
# Для Windows: запобігає проблемам з динамічними бібліотеками MSVC
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Створюємо бібліотеку з вашим класом
# Це дозволяє використовувати Vector.cpp в обох виконуваних файлах
add_library(VectorLib Vector.cpp Vector.h)

# 3. Основна програма (main.cpp)
add_executable(VectorApp main.cpp)
target_link_libraries(VectorApp PRIVATE VectorLib)

# 4. Тести (UnitTest.cpp)
# Використовуємо gtest_main, щоб не писати свій main у тестах
add_executable(UnitTest UnitTest.cpp)
target_link_libraries(UnitTest PRIVATE VectorLib gtest_main)

# 5. Реєстрація тестів для запуску через ctest
include(CTest)
enable_testing()
add_test(NAME AllVectorTests COMMAND UnitTest)