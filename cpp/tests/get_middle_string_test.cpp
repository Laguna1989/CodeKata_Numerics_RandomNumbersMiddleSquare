#include "middle_square.hpp"
#include <gtest/gtest.h>

TEST(GetMiddleStringTest, middleStringOneOfFour)
{
    std::string const input = "ABCD";
    ASSERT_EQ(get_middle_string(input, 1), "C");
}

TEST(GetMiddleStringTest, middleStringTwoOfFour)
{
    std::string const input = "ABCD";
    ASSERT_EQ(get_middle_string(input, 2), "BC");
}

TEST(GetMiddleStringTest, middleStringThreeOfFour)
{
    std::string const input = "ABCD";
    ASSERT_EQ(get_middle_string(input, 3), "BCD");
}

TEST(GetMiddleStringTest, middleStringFourOfFour)
{
    std::string const input = "ABCD";
    ASSERT_EQ(get_middle_string(input, 4), "ABCD");
}

TEST(GetMiddleStringTest, middleStringOneOfFive)
{
    std::string const input = "ABCDE";
    ASSERT_EQ(get_middle_string(input, 1), "C");
}

TEST(GetMiddleStringTest, middleStringTwoOfFive)
{
    std::string const input = "ABCDE";
    ASSERT_EQ(get_middle_string(input, 2), "BC");
}

TEST(GetMiddleStringTest, middleStringThreeOfFive)
{
    std::string const input = "ABCDE";
    ASSERT_EQ(get_middle_string(input, 3), "BCD");
}

TEST(GetMiddleStringTest, middleStringFourOfFive)
{
    std::string const input = "ABCDE";
    ASSERT_EQ(get_middle_string(input, 4), "ABCD");
}

TEST(GetMiddleStringTest, MoreCharactersThanStringLengthRaisesException)
{
    std::string const input = "A";

    ASSERT_THROW(get_middle_string(input, 4), std::out_of_range);
}
