#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// find and print all elements greater than 6
void printAllGreaterThen6With_foreach(const std::vector<int>& v)
{
    std::cout << "All elements greater than 6 using for_each: ";
    std::ranges::for_each(v, [](const auto el) {
        if (el > 6) {
            std::cout << el;
        }
    });
    std::cout << std::endl;
}

// find and print all elements greater than 6
void printAllGreaterThen6With_copy_if(const std::vector<int>& v)
{
    std::cout << "All elements greater than 6 using copy_if: ";
    std::copy_if(begin(v),
                 end(v),
                 std::ostream_iterator<int>(std::cout, "\t"),
                 [](const auto el) { return el > 6; });
    std::cout << std::endl;
}

// Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
// find and print all elements equal to 2, 4, 6 or 8
void printAllEqualTo2_4_6_8(const std::vector<int>& v)
{
    std::cout << "all elements equal to 2, 4, 6 or 8 with foreach: ";
    std::vector<int> ref_vector { 2, 4, 6, 8 };
    std::for_each(begin(v),
                  end(v),
                  [&](const auto el) {
                      if (std::ranges::find(ref_vector, el) != ref_vector.end()) {
                          std::cout << el;
                      }
                  });
    std::cout << std::endl;
}

void printAllEqualTo2_4_6_8_with_copy_if(const std::vector<int>& v)
{
    std::cout << "all elements equal to 2, 4, 6 or 8 with copy_if: ";
    std::vector<int> ref_vector { 2, 4, 6, 8 };
    std::copy_if(begin(v),
                 end(v),
                 std::ostream_iterator<int>(std::cout, " "),
                 [&](const auto el) {
                     return (el == 2 || el == 4 || el == 6 || el == 8);
                 });
    std::cout << std::endl;
}

// Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
// Search vector v for ranges {6, 6} and {7,7};
void searchForRanges(const std::vector<int>& v,
                     const std::vector<int>& searchedRange)
{
    auto it = begin(v);
    do {
        it = std::search(it,
                         end(v),
                         begin(searchedRange),
                         end(searchedRange));
        if (it != v.end()) {
            std::cout << "Found range in pos: "
                      << std::distance(begin(v), it)
                      << '\n';
            ++it;
        }
    } while (it != end(v));
}

// Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
// Search vector v for ranges {6, 6} and {7,7};
void searchForRanges(const std::vector<int>& v, std::size_t repeat, int value)
{
    auto it = begin(v);
    do {
        it = std::search_n(it,
                           end(v),
                           repeat,
                           value);
        if (it != v.end()) {
            std::cout << "Found range in pos: "
                      << std::distance(begin(v), it)
                      << '\n';
            ++it;
        }
    } while (it != end(v));
}

// train std::adjacent_find use on a vector
void tryAdjacentFind(const std::vector<int>& v)
{
    auto it = std::adjacent_find(begin(v), end(v));
    if (it != end(v)) {
        std::cout << "Adjacent value: "
                  << *it
                  << " found in position: "
                  << std::distance(begin(v), it)
                  << '\n';
    }
}

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    printAllGreaterThen6With_foreach(v);
    printAllGreaterThen6With_copy_if(v);
    printAllEqualTo2_4_6_8(v);
    printAllEqualTo2_4_6_8_with_copy_if(v);
    searchForRanges(v, std::vector { 6, 6 });
    searchForRanges(v, std::vector { 7, 7 });
    searchForRanges(v, 2, 6);
    searchForRanges(v, 2, 7);
    tryAdjacentFind(v);
    return 0;
}
