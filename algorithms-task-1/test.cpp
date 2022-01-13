#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

// Policz, ile jest elementów większych lub równych 5
TEST(testElementsCount, testElementsLessOrEqualFive)
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    auto less_or_equal_five_count = std::count_if(v.begin(),
                                                  v.end(),
                                                  [](const auto el) {
                                                      return el <= 5;
                                                  });
    ASSERT_EQ(7, less_or_equal_five_count);
}

// Sprawdź, czy istnieje element mniejszy od 1
TEST(testElementsCount, testIfAnyLessThanOne)
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    bool any_less_than_five = std::any_of(begin(v), end(v), [](const auto el) {
        return el < 1;
    });
    ASSERT_EQ(false, any_less_than_five);
}

// Sprawdź, czy wszystkie elementy są większe od1
TEST(testElementsCount, testIfAnyGreaterThanOne)
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    bool all_greater_than_five = std::all_of(begin(v), end(v), [](const auto el) {
        return el > 1;
    });
    ASSERT_EQ(false, all_greater_than_five);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
