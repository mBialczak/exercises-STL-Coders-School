#include "functions.hpp"

#include <gtest/gtest.h>

class TestFixture : public testing::Test
{
  public:
    TestFixture();

  protected:
    std::vector<std::pair<int, std::string>> v_;
    std::vector<std::pair<int, std::string>> empty_;
};

TestFixture::TestFixture()
    : v_(std::vector<std::pair<int, std::string>> {
        { 0, "Zero" },
        { 1, "One" },
        { 2, "Two" },
        { 3, "Three" },
        { 4, "Four" },
        { 5, "Five" } })
{ }

TEST_F(TestFixture, SubtaskOneEmptyVecTest)
{
    auto resV = subtaskOne(empty_);
    std::vector<int> correctV {};

    ASSERT_EQ(correctV, resV);
}

TEST_F(TestFixture, SubtaskOneCodersSchoolVecTest)
{
    auto resV = subtaskOne(v_);
    std::vector<int> correctV { 0, 1, 2, 3, 4, 5 };

    ASSERT_EQ(correctV, resV);
}

TEST_F(TestFixture, SubtaskTwoEmptyVecTest)
{
    auto resV = subtaskTwo(empty_);
    std::vector<std::string> correctV {};

    ASSERT_EQ(correctV, resV);
}

TEST_F(TestFixture, SubtaskTwoCodersSchoolVecTest)
{
    auto resV = subtaskTwo(v_);
    std::vector<std::string> correctV = {
        "Zero:0",
        "One:1",
        "Two:2",
        "Three:3",
        "Four:4",
        "Five:5"
    };

    ASSERT_EQ(correctV, resV);
}

TEST(GenerateLettersTest, everySecondLetterTest)
{
    std::vector<char> correct {
        'a',
        'c',
        'e',
        'g',
        'i',
        'k',
        'm',
        'o',
        'q',
        's',
        'u',
        'w',
        'y'
    };

    auto resV = subtaskThree();

    ASSERT_EQ(correct, resV);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}