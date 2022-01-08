#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(int argc, char const* argv[])
{
    // 1.
    auto multiply = [](int lhs, int rhs) {
        return lhs * rhs;
    };
    std::cout << "Subtask 1 example. Multiply 4 * 5= "
              << multiply(4, 5) << std::endl;

    //2.
    auto add_parens = [](std::string& text) {
        text.insert(text.cbegin(), '\"');
        text += '\"';
    };
    std::string cow { "Cow" };
    std::cout << cow << " after add_parens lambda is: ";
    add_parens(cow);
    std::cout << cow << std::endl;

    //3.
    auto star = [count = 1]() mutable {
        std::string symbol(count, '*');
        std::cout << symbol << std::endl;
        count += 1;
    };
    for (auto i = 0; i < 5; ++i) {
        star();
    }

    //4.
    std::vector vec { 1, 2, 3, 4, 5 };

    auto print = [&vec]() {
        for (auto el : vec) {
            std::cout << el << '\t';
        }
        std::cout << std::endl;
    };

    print();
    //6.
    auto printValue = [](auto num) {
        std::cout << num << std::endl;
    };

    printValue(5);
    printValue(3.14L);

    //7.
    std::list li { 2.0, 3.0, 4.0, 5.0 };
    std::for_each(li.begin(), li.end(), printValue);
    std::for_each(vec.begin(), vec.end(), printValue);

    return 0;
}
