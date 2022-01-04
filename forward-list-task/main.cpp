#include <array>
#include <forward_list>
#include <iostream>

// prints all container elements to console
template <class Container>
void print(const Container& container)
{
    for (auto&& el : container) {
        std::cout << el << ' ';
    }
    std::cout << "Container size in bytes: " << sizeof(container) << std::endl;
}

int main(int argc, char const* argv[])
{
    std::cout << "empty forward_list size in bytes=\n "
              << sizeof(std::forward_list<int> {}) << std::endl;

    std::forward_list elements { 0, 1, 2, 3, 4, 5, 6 };

    print(elements);

    auto it = elements.begin();
    std::advance(it, 1);
    elements.erase_after(it);
    elements.emplace_front(10);
    elements.reverse();
    elements.emplace_front(10);
    elements.reverse();
    print(elements);

    it = elements.begin();
    std::advance(it, 2);
    elements.emplace_after(it, 20);

    print(elements);
    return 0;
}
