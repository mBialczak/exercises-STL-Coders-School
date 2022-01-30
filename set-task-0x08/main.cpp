#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <set>
/*
  1.  Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
  2.  Wstaw nowe elementy: -10, 0, 10, 100, -100
  3.  Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
  4.  Wstaw nowe elementy: -10, 0, 10, 100, -100
  5.  Połącz oba zbiory w jeden (ma to być std::multiset)
  6.  Znajdź wszystkie elementy równe 0 i 50
    Co każdy krok wypisuj zawartości kontenerów.
*/
template <typename C>
void print(const C& container)
{
    for (const auto el : container) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
};

int main()
{
    // 1.  Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
    std::array<int, 41> temp_array;
    std::iota(begin(temp_array), end(temp_array), -20);
    std::set<int, std::greater<int>> numbers(begin(temp_array),
                                             end(temp_array));
    print(numbers);
}
