#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
/*
Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:
    Wrocław (x = 17, y = 51)
    Moskwa (x = 37, y = 55)
    Nowy Jork (x = -74, y = 40)
    Sydney (x = 151, y = -33)

Część A - łatwiejsza

  1a. Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
  2a. Sprawdź czy w mapie jest element, który znajduje się w promieniu 70
      od środka układu współrzędnych (0, 0)
  3a. Pobierz i wypisz współrzędne Sydney

Część B - trudniejsza

  1b. Skopiuj te dane do mapy std::map<Point, std::string>
  2b. Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70
      od środka układu współrzędnych (0, 0)
  3b. Pobierz i wypisz współrzędne Sydney

*/

struct Point
{
    int x;
    int y;
};

// operator allowing for sorting Points based on the distance from point [0,0]
bool operator<(const Point lhs, const Point rhs)
{
    auto lhs_distance_sq = pow(lhs.x, 2) + pow(lhs.y, 2);
    auto rhs_distance_sq = pow(rhs.x, 2) + pow(rhs.y, 2);
    return lhs_distance_sq < rhs_distance_sq;
}

int main(int argc, char const* argv[])
{
    // 1a.
    std::map<std::string, Point> citiesA = {
        { "Wrocław", { 17, 51 } },
        { "Moskwa", { 47, 55 } },
        { "Nowy Jork", { -74, 40 } },
        { "Sydney", { 151, -33 } }
    };

    // 2a. Sprawdź czy w mapie jest element, który znajduje się w promieniu 70
    //      od środka układu współrzędnych (0, 0)
    auto point_in_range = [radius = 70](auto point) {
        auto [x, y] = point;
        auto distance_squared = pow(x, 2) + pow(y, 2);
        return distance_squared < pow(radius, 2);
    };

    bool is_city_in_radious = std::ranges::any_of(citiesA.cbegin(),
                                                  citiesA.cend(),
                                                  [&](const auto& entry) {
                                                      return point_in_range(entry.second);
                                                  });

    std::cout << "There is a city in range below 70: "
              << std::boolalpha << is_city_in_radious << '\n';

    // 3a. Pobierz i wypisz współrzędne Sydney
    auto search_result = citiesA.find("Sydney");
    if (search_result != citiesA.end()) {
        std::cout << "Sydney coords: x="
                  << search_result->second.x
                  << " y=" << search_result->second.y << std::endl;
    }

    //  1b. Skopiuj te dane do mapy std::map<Point, std::string>
    std::map<Point, std::string> citiesB;
    std::transform(citiesA.begin(),
                   citiesA.end(),
                   std::inserter(citiesB, citiesB.begin()),
                   [](const auto& el) -> std::pair<Point, std::string> {
                       return { el.second, el.first };
                   });

    // 2b. Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70
    // od środka układu współrzędnych (0, 0)
    auto it = std::ranges::find_if(citiesB,
                                   [&](const auto& entry) {
                                       return point_in_range(entry.first);
                                   });
    if (it != citiesB.end()) {
        std::cout << "There is a city in citiesB in range less then 70 from 0,0\n";
    }

    //  3b. Pobierz i wypisz współrzędne Sydney
    it = std::ranges::find_if(citiesB,
                              [&](const auto& entry) {
                                  return entry.second == "Sydney";
                              });

    if (it != citiesB.end()) {
        std::cout << "Sydney coords: x="
                  << search_result->second.x
                  << " y=" << search_result->second.y << std::endl;
    }

    return 0;
}
