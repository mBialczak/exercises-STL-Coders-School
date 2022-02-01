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

    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

// operator allowing for sorting Points based on the distance from point [0,0]
// bool operator<(const Point lhs, const Point rhs)
// {
//     auto lhs_distance_sq = pow(lhs.x, 2) + pow(lhs.y, 2);
//     auto rhs_distance_sq = pow(rhs.x, 2) + pow(rhs.y, 2);
//     return lhs_distance_sq < rhs_distance_sq;
// }

// injected hash specialization version
template <>
struct std::hash<Point>
{
    std::size_t operator()(const Point& point) const noexcept
    {
        auto hash_sum = std::hash<int> {}(point.x + point.y);
        auto hash_mult = std::hash<int> {}(point.x * point.y);
        return hash_sum ^ hash_mult;
    }
};

// finds a desired city in an unordered_map and prints coordinates
// for 3a
void printCity(const std::unordered_map<std::string, Point>& container,
               const std::string& cityName)
{
    auto search_result = container.find(cityName);
    if (search_result != container.end()) {
        std::cout << cityName << " "
                  << "coords: x="
                  << search_result->second.x
                  << " y=" << search_result->second.y << std::endl;
    }
}

// finds a desired city in an unordered_map and prints coordinates
// for 3b
template <typename Umap>
void printCity(const Umap& container, const std::string& cityName)
{
    auto it = std::ranges::find_if(container,
                                   [&](const auto& entry) {
                                       return entry.second == cityName;
                                   });

    if (it != container.end()) {
        std::cout << cityName << " "
                  << "coords: x="
                  << it->first.x
                  << " y=" << it->first.y << std::endl;
    }
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
    printCity(citiesA, "Sydney");

    // PART B
    //  1b. Skopiuj te dane do mapy std::unordered_map<Point, std::string>

    // custom hash for unordered_map<Point,std::string>
    auto PointHash = [](const auto& point) {
        auto hash_sum = std::hash<int> {}(point.x + point.y);
        auto hash_mult = std::hash<int> {}(point.x * point.y);
        return hash_sum & hash_mult;
    };

    // custom equality compare for unordered_map<Point,std::string>
    auto PointEqual = [](const auto& pointA, const auto& pointB) {
        return pointA.x == pointB.x && pointA.y == pointB.y;
    };

    // NOTE: First opiton with custom hash and lambda equality comparison - works
    std::unordered_map<Point,
                       std::string,
                       decltype(PointHash),
                       decltype(PointEqual)>
        citiesB;

    // NOTE: Second option with injected std::hash specialization and Point::operator==()usage
    std::unordered_map<Point, std::string> citiesC;

    std::transform(citiesA.begin(),
                   citiesA.end(),
                   std::inserter(citiesB, citiesB.begin()),
                   [](const auto& el) -> std::pair<Point, std::string> {
                       return { el.second, el.first };
                   });

    std::transform(citiesA.begin(),
                   citiesA.end(),
                   std::inserter(citiesC, citiesC.begin()),
                   [](const auto& el) -> std::pair<Point, std::string> {
                       return { el.second, el.first };
                   });

    // // 2b. Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70
    // // od środka układu współrzędnych (0, 0)
    for (const auto& [point, city] : citiesB) {
        auto [is_in_range, range] = point_in_range(point);
        if (is_in_range) {
            std::cout << city << "-> distance from origin: " << sqrt(range) << std::endl;
        }
    }

    for (const auto& [point, city] : citiesC) {
        auto [is_in_range, range] = point_in_range(point);
        if (is_in_range) {
            std::cout << city << "-> distance from origin: " << sqrt(range) << std::endl;
        }
    }

    // //  3b. Pobierz i wypisz współrzędne Sydney
    printCity(citiesB, "Sydney");
    printCity(citiesC, "Sydney");

    return 0;
}
