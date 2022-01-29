#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

/*
    Stwórz multimapę i wypełnij ją podanymi wartościami
    Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.
*/
void printAllwordsWithLenghth(const std::multimap<int, std::string>& dict,
                              unsigned length)
{
    std::for_each(dict.cbegin(),
                  dict.cend(),
                  [length](const auto& node) {
                      if (node.second.length() == length) {
                          std::cout << node.second << "\t";
                      }
                  });
}

int main()
{
    std::multimap<int, std::string> map;
    map.insert({ 5, "Ala" });
    map.insert({ 5, "Ma" });
    map.insert({ 5, "Kota" });
    map.insert({ 5, "A" });
    map.insert({ 5, "Kot" });
    map.insert({ 5, "Ma" });
    map.insert({ 5, "Ale" });

    printAllwordsWithLenghth(map, 3);

    return 0;
}
