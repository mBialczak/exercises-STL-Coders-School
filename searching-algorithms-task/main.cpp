#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

/*

*/

struct Point {
  int x, y;
};

std::ostream &operator<<(std::ostream &stream, const Point point) {
  return stream << '(' << point.x << ',' << point.y << ')';
}

template <typename Container> void print(const Container &container) {
  std::copy(
      begin(container), end(container),
      std::ostream_iterator<typename Container::value_type>(std::cout, " "));
  std::cout << std::endl;
}

int main(int argc, const char **argv) {
  //  1.  Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1},
  //  {0, 2}, {2, 2}};
  std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4},
                         {4, 1}, {0, 2}, {2, 2}};
  //  2.  Utwórz funkcję do wypisywania zawartości kontenera d
  print(d);
  //  3.  Napisz 2 komparatory:
  //       pointXCompare, który porównuje tylko wartości x ze struktury Point
  //       pointYCompare, który porównuje tylko wartości y ze struktury Point
  auto pointXCompare = [](const auto &lhs, const auto &rhs) {
    return lhs.x < rhs.x;
  };

  auto pointYCompare = [](const auto &lhs, const auto &rhs) {
    return lhs.y < rhs.y;
  };

  //  4.  Sprawdź czy d jest posortowane względem pointXCompare oraz
  //  pointYCompare
  std::cout << "Container is sorted by x coordinate: " << std::boolalpha
            << std::is_sorted(begin(d), end(d), pointXCompare) << std::endl;

  std::cout << "Container is sorted by y coordinate: "
            << std::is_sorted(begin(d), end(d), pointYCompare) << std::endl;

  // 5.  Użyj stable_sort do posortowania d względem wartości x
  std::stable_sort(begin(d), end(d), pointXCompare);
  print(d);
  // 6. Użyj sort do posortowania d względem wartości y
  std::ranges::sort(d, pointYCompare);
  print(d);

  return 0;
}
