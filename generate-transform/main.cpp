// #include <algorithm>
// #include <list>
#include "functions.hpp"

#include <iostream>
#include <string>
#include <vector>

/*
    1. Create a vector of ints called v2 and fill it with all ints
       (first elements of the pair) of vector v
    2. Create a vector of strings called v3 and fill it with a concatenation 
       of string and int (string + : + int_element) from every pair of vector v
    3. Create a vector of chars called v4 and fill it with
       every second letter of the alphabet
*/

// helper function printing all elements of a container
template <typename Container>
void printContainer(const Container& container)
{
    std::for_each(begin(container),
                  end(container),
                  [](const auto el) {
                      std::cout << el << " ";
                  });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::pair<int, std::string>> v {
        { 0, "Zero" },
        { 1, "One" },
        { 2, "Two" },
        { 3, "Three" },
        { 4, "Four" },
        { 5, "Five" }
    };

    // 1. Create a vector of ints called v2 and fill it with all ints
    //    (first elements of the pair) of vector v
    std::cout << "Subtask one result: ";
    printContainer(subtaskOne(v));

    //  2. Create a vector of strings called v3 and fill it with a concatenation
    //      of string and int (string + : + int_element) from every pair of vector v
    std::cout << "Subtask two result:";
    printContainer(subtaskTwo(v));

    // 3. Create a vector of chars called v4 and fill it with
    //     every second letter of the alphabet
    std::cout << "Subtask three result: ";
    printContainer(subtaskThree());

    return 0;
}
