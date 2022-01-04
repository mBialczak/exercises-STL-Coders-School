#include <iostream>
#include <vector>

void printSizeCapacity(const std::vector<int>& vec)
{
    std::cout << "vec size: " << vec.size()
              << "\nvec capacity: " << vec.capacity()
              << "\nsize of vector object in bytes: "
              << sizeof(vec)
              << std::endl;
}

int main(int argc, char const* argv[])
{
    std::vector<int> vec;
    printSizeCapacity(vec);

    vec.resize(10, 5);
    printSizeCapacity(vec);

    vec.reserve(20);
    printSizeCapacity(vec);

    vec.shrink_to_fit();
    printSizeCapacity(vec);

    return 0;
}
