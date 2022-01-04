#include <array>
#include <iostream>
#include <list>

// prints all container elements to console
template <class Container>
void printContainer(const Container& container)
{
    for (auto&& el : container) {
        std::cout << el << ' ';
    }

    std::cout << "Container size in bytes: " << sizeof(container) << std::endl;
}

int main(int argc, char const* argv[])
{
    std::cout << "empty list size in bytes= "
              << sizeof(std::list<int> {}) << std::endl;
    std::list elements { 0, 1, 2, 3, 4, 5 };

    printContainer(elements);

    auto it = elements.begin();
    std::advance(it, 2);
    elements.erase(it);
    elements.emplace_back(10);
    elements.emplace_front(10);

    printContainer(elements);

    it = elements.begin();
    std::advance(it, 3);
    elements.emplace(it, 20);

    std::array<int, 8> table;
    std::copy(elements.begin(), elements.end(), table.begin());

    printContainer(table);

    return 0;
}
