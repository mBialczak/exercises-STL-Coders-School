#include <algorithm>
#include <array>
#include <execution>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
/*
  1.  Utwórz wektor v1 z liczbami od 1 do 1000
  2.  Oblicz sumę tych liczb
  3.  Utwórz wektor v2 z 1000 elementów powtarzających się
      w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
  4.  Oblicz iloczyn skalarny wektorów v1 i v2
  5.  Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2
*/

// prints a container to console
template <typename Container>
void print(const Container& container)
{
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename Container::value_type>(std::cout, " "));
    std::cout << '\n';
}

int main()
{
    // 1. Utwórz wektor v1 z liczbami od 1 do 1000
    std::vector<int> v1(1000, 0);
    std::iota(v1.begin(), v1.end(), 1);

    // 2.  Oblicz sumę tych liczb
    auto sum = std::reduce(std::execution::par,
                           begin(v1),
                           end(v1));
    std::cout << "Sum of v1 elements: " << sum << '\n';

    // 3. Utwórz wektor v2 z 1000 elementów powtarzających się
    // w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
    std::vector v2(1000, 0);
    auto generator = [state = 0]() mutable {
        static constexpr std::array<int, 4> possible_values { -1, 0, 1, 0 };
        int generated_value = possible_values[state % 4];
        ++state;
        return generated_value;
    };
    std::generate(begin(v2), end(v2), generator);

    // 4.  Oblicz iloczyn skalarny wektorów v1 i v2
    std::cout << "Inner product of v1 and v2 = "
              << std::inner_product(begin(v1),
                                    end(v1),
                                    begin(v2),
                                    0)
              << std::endl;

    // 5. Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2
    std::cout << std::transform_reduce(begin(v1),
                                       end(v1),
                                       begin(v2),
                                       0,
                                       std::plus<int> {},
                                       [](const auto v1_el, const auto v2_el) {
                                           if (v2_el > 0) {
                                               return v1_el;
                                           }
                                           return 0;
                                       });

    return 0;
}