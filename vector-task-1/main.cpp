#include <iostream>
#include <vector>

void sizeInfo(const std::vector<int>& vec)
{
    std::cout << "vec current size: "
              << vec.size()
              << "\n vec max size: "
              << vec.max_size();
}

int main(int argc, char const* argv[])
{
    std::vector vec { 1, 2, 4, 5, 6 };
    vec.erase(vec.begin());
    vec.emplace_back(5);
    vec.emplace(vec.begin(), 12);

    sizeInfo(vec);

    std::cout << "\n vec content: ";

    for (auto num : vec) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    vec.clear();
    sizeInfo(vec);

    return 0;
}
