#include <algorithm>
#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    for (auto&& el : arr) {
        std::cout << el << '\t';
    }
    std::cout << std::endl;
}

int main(int argc, const char** argv)
{
    std::array<int, 10> arr1;
    arr1.fill(5);
    arr1[3] = 3;

    std::array<int, 10> arr2;

    std::swap(arr1, arr2);

    std::cout << "Array 1: " << std::endl;
    printArray(arr1);
    std::cout << "Array 2: " << std::endl;
    printArray(arr2);

    return 0;
}