#include "functions.hpp"

#include <algorithm>
#include <iterator>

// Create a vector of ints called v2 and fill it with all ints
// (first elements of the pair) of vector v
std::vector<int> subtaskOne(const std::vector<std::pair<int, std::string>>& v)
{
    std::vector<int> v2;
    v2.reserve(v.size());
    std::transform(begin(v),
                   end(v),
                   std::back_inserter(v2),
                   [](const auto& el) { return el.first; });

    return v2;
}

// Create a vector of strings called v3 and fill it with a concatenation
// of string and int (string + : + int_element) from every pair of vector v
std::vector<std::string> subtaskTwo(const std::vector<std::pair<int, std::string>>& v)
{
    std::vector<std::string> v3;
    v3.reserve(v.size());
    std::ranges::transform(v,
                           std::back_inserter(v3),
                           [](const auto& el) {
                               return el.second + ':' + std::to_string(el.first);
                           });

    return v3;
}

// Create a vector of chars called v4 and fill it with
// every second letter of the alphabet
std::vector<char> subtaskThree()
{
    // const std::string alphabet { "abcdefghijklmnopqrstuvwxyz" };
    // latin alphabet is supposed to contain 26 letters, so we take half
    const auto size = 13;
    std::vector<char> result(size);
    std::generate_n(begin(result),
                    size,
                    [letter = 'a' - 2]() mutable {
                        letter += 2;
                        return letter;
                    });

    return result;
}