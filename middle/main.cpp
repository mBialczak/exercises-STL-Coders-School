#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <class Iter>
auto middle(Iter first, Iter last)
{
    return std::next(first, (std::distance(first, last) - 1) / 2);
}

template <class Container>
void printMiddle(const Container& container)
{
    std::cout << *middle(container.cbegin(), container.cend())
              << std::endl;
}

template <class Container>
void printAll(const Container& container)
{
    std::for_each(container.cbegin(),
                  container.cend(),
                  [](const auto& element) {
                      std::cout << element << ' ';
                  });
    std::cout << std::endl;
}

int main(int argc, char const* argv[])
{
    std::vector vec1 { 1, 2, 3, 4, 5 };
    std::vector vec2 { 11, 12, 13, 14 };
    std::list list1 { 1, 2, 3, 4, 5 };
    std::list list2 { 11, 12, 13, 14 };
    std::forward_list f_list1 { 1, 2, 3, 4, 5 };
    std::forward_list f_list2 { 11, 12, 13, 14 };
    std::array arr1 { 1, 2, 3, 4, 5 };
    std::array arr2 { 11, 12, 13, 14 };
    std::deque deque1 { 1, 2, 3, 4, 5 };
    std::deque deque2 { 11, 12, 13, 14 };

    std::cout << "Middle for vector1: ";
    printAll(vec1);
    printMiddle(vec1);
    std::cout << "Middle For vector2: ";
    printAll(vec2);
    printMiddle(vec2);

    std::cout << "Middle for list1: ";
    printAll(list1);
    printMiddle(list1);
    std::cout << "Middle for list2: ";
    printAll(list2);
    printMiddle(list2);

    std::cout << "Middle for forward_list1: ";
    printAll(f_list1);
    printMiddle(f_list1);
    std::cout << "Middle for forward_list2: ";
    printAll(f_list2);
    printMiddle(f_list2);

    std::cout << "Middle for array1: ";
    printAll(arr1);
    printMiddle(arr1);
    std::cout << "Middle for array2: ";
    printAll(arr2);
    printMiddle(arr2);

    std::cout << "Middle for deque1: ";
    printAll(deque1);
    printMiddle(deque1);
    std::cout << "Middle for deque2: ";
    printAll(deque2);
    printMiddle(deque2);
    return 0;
}
