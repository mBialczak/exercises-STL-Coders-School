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
    const std::string alphabet { "abcdefghijklmnopqrstuvwxyz" };
    std::vector<char> result(alphabet.size() / 2);
    std::generate(begin(result),
                  end(result),
                  [&, n = 0]() mutable {
                      char letter = alphabet.at(n);
                      n += 2;
                      return letter;
                  });

    return result;
}