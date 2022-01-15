#pragma once

#include <string>
#include <vector>

// Create a vector of ints called v2 and fill it with all ints
// (first elements of the pair) of vector v
std::vector<int> subtaskOne(const std::vector<std::pair<int, std::string>>& v);

// Create a vector of strings called v3 and fill it with a concatenation
// of string and int (string + : + int_element) from every pair of vector v
std::vector<std::string> subtaskTwo(const std::vector<std::pair<int, std::string>>& v);

// Create a vector of chars called v4 and fill it with
// every second letter of the alphabet
std::vector<char> subtaskThree();