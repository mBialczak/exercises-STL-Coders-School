#include <deque>
#include <iostream>

// prints all container elements to console template <class Container>
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
    std::deque<int> container;
    std::cout << "Empty container size in bytes: " << sizeof(container) << std::endl;
    container.insert(container.begin(), { 1, 2, 3, 4, 5 });
    print(container);
    container.erase(container.begin() + 3);
    container.erase(container.begin() + 1);
    container.emplace_front(30);
    container.emplace_back(30);
    print(container);
    container.emplace(container.begin() + 3, 20);
    print(container);
}
