#include <iostream>

struct is_divisable_by_six
{
    bool operator()(int num)
    {
        return (num % 6 == 0);
    }
};

int main(int argc, char const* argv[])
{
    is_divisable_by_six checker;

    std::cout << std::boolalpha;
    std::cout << "Is 3 divisible by 6: " << is_divisable_by_six {}(3) << '\n';
    std::cout << "Is 6 divisible by 6: " << checker(6) << std::endl;
    return 0;
}
