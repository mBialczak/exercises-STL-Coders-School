#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
/*
Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:
    Wrocław (x = 17, y = 51)
    Moskwa (x = 37, y = 55)
    Nowy Jork (x = -74, y = 40)
    Sydney (x = 151, y = -33)

Część A - łatwiejsza

  1a. Stwórz std::unordered_map<std::string, Point>, która będzie przechowywać powyższe miejsca
  2a. Sprawdź czy w mapie jest element, który znajduje się w promieniu 70
      od środka układu współrzędnych (0, 0)
  3a. Pobierz i wypisz współrzędne Sydney

Część B - trudniejsza

  1b. Skopiuj te dane do mapy std::unordered_map<Point, std::string>
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

int main()
{
    // 1a.
    std::unordered_map<std::string, Point> citiesA = {
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
        return std::pair<bool, double> { distance_squared < pow(radius, 2),
                                         distance_squared };
    };

    for (const auto& [city, point] : citiesA) {
        auto [is_in_range, range] = point_in_range(point);
        if (is_in_range) {
            std::cout << city << "-> distance from origin: " << sqrt(range) << std::endl;
        }
    }

    // 3a. Pobierz i wypisz współrzędne Sydney
    auto search_result = citiesA.find("Sydney");
    if (search_result != citiesA.end()) {
        std::cout << "Sydney coords: x="
                  << search_result->second.x
                  << " y=" << search_result->second.y << std::endl;
    }

    //  1b. Skopiuj te dane do mapy std::unordered_map<Point, std::string>
    auto PointHash = [](const auto& point) {
        return std::hash<int> {}(point.x + point.y);
    };

    auto PointEqual = [](const auto& pointA, const auto& pointB) {
        return pointA.x == pointB.x && pointA.y == pointB.y;
    };

    std::unordered_map<Point,
                       std::string,
                       decltype(PointHash),
                       decltype(PointEqual)>
        citiesB;

    std::transform(citiesA.begin(),
                   citiesA.end(),
                   std::inserter(citiesB, citiesB.begin()),
                   [](const auto& el) -> std::pair<Point, std::string> {
                       return { el.second, el.first };
                   });

    // // 2b. Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70
    // // od środka układu współrzędnych (0, 0)
    // auto it = std::ranges::find_if(citiesB,
    //                                [&](const auto& entry) {
    //                                    return point_in_range(entry.first);
    //                                });
    // if (it != citiesB.end()) {
    //     std::cout << "There is a city in citiesB in range less then 70 from 0,0\n";
    // }

    // //  3b. Pobierz i wypisz współrzędne Sydney
    // it = std::ranges::find_if(citiesB,
    //                           [&](const auto& entry) {
    //                               return entry.second == "Sydney";
    //                           });

    // if (it != citiesB.end()) {
    //     std::cout << "Sydney coords: x="
    //               << search_result->second.x
    //               << " y=" << search_result->second.y << std::endl;
    // }

    return 0;
}
