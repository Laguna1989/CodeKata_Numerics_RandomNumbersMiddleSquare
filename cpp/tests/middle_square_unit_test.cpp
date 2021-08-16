#include "middle_square.hpp"
#include <gtest/gtest.h>

TEST(MiddleSquareTest, CorrectResultFor0)
{
    std::uint32_t const initial = 0;

    auto const result = middle_square(initial);
    ASSERT_EQ(result, 0);
}

TEST(MiddleSquareTest, CorrectResultFor1)
{
    std::uint32_t const initial = 1;

    auto const result = middle_square(initial);
    ASSERT_EQ(result, 0);
}

TEST(MiddleSquareTest, CorrectResultFor1234)
{
    std::uint32_t const initial = 1234;

    auto const result = middle_square(initial);
    ASSERT_EQ(result, 5227);
}

TEST(MiddleSquareTest, CorrectResultFor5227)
{
    std::uint32_t const initial = 5227;

    auto const result = middle_square(initial);
    ASSERT_EQ(result, 3215);
}

class MiddleSquareTestSize3TestFixture
    : public ::testing::TestWithParam<std::tuple<std::uint32_t, std::uint32_t>> {
};

TEST_P(MiddleSquareTestSize3TestFixture, CorrectResultForSize3)
{
    std::uint32_t const initial = std::get<0>(GetParam());
    std::uint32_t const expected_result = std::get<1>(GetParam());
    auto const result = middle_square(initial, 3);

    ASSERT_EQ(result, expected_result);
}

INSTANTIATE_TEST_SUITE_P(MiddleSquareTestSize3Test, MiddleSquareTestSize3TestFixture,
    ::testing::Values(std::make_tuple(4, 1), std::make_tuple(9, 8), std::make_tuple(11, 2),
        std::make_tuple(12, 4), std::make_tuple(13, 6), std::make_tuple(14, 9)));
