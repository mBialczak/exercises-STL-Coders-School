#include <algorithm>
#include <execution>
#include <vector>

int main(int argc, char const* argv[])
{
    std::vector<int> v(1'000'000);
    std::generate(std::execution::par,
                  begin(v),
                  end(v),
                  [n = 0]() mutable { return n++; });
    return 0;
}
