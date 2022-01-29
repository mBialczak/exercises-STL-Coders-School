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

    bool is_city_in_radious =
        std::ranges::any_of(citiesA.cbegin(),
                            citiesA.cend(),
                            [](const auto& entry) {
                                auto [x, y] = entry.second;
                                auto distance_squared = pow(x, 2) + pow(y, 2);
                                constexpr auto radious_sqared = pow(70, 2);
                                return distance_squared < radious_sqared;
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
    return 0;
}
