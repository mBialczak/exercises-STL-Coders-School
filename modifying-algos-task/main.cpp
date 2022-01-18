#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

//1. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
//2. Usuń wszystkie duplikaty z v
//3. Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
//4. Pomieszaj losowo wszystkie elementy
//5. Wypisz je raz jeszcze

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    //2.
    std::ranges::sort(v);
    auto new_end_it = std::unique(begin(v), end(v));
    v.erase(new_end_it, v.end());
    //3.
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //4.
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(begin(v), end(v), generator);
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
