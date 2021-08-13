#include <gtest/gtest.h>
#include <sstream>
#include "middle_square.hpp"

TEST(MiddleSquareDistribution, FullDistribution)
{
    std::uint32_t seed = 1234;
    std::map<std::uint32_t, std::uint32_t > distribution;

    for (int i = 0; i != 1000; ++i)
    {
        seed = middle_square(seed, 8);
        if (distribution.count(seed) == 0) {
            distribution[seed] = 0;
        }
        distribution[seed]++;
    }

    for (auto const& kvp : distribution)
    {
        std::cout << kvp.first << " " <<  kvp.second << std::endl;
    }

}


TEST(MiddleSquareDistribution, LastDecimalDigit)
{
    // calculate 5000 pseudo random values with the randu algorithm

    // for each value get the last decimal digit

    // verify that only odd digits appear

    std::size_t const N = 50000;
    std::map<int, int> histo;
    std::uint32_t seed = 1234;
    for (auto i = 0u; i != N; ++i) {
        seed = middle_square(seed, 8);

        std::stringstream stream;
        stream << seed;
        auto string = stream.str();
        string = string.substr(string.size() - 1);
        int v = std::stoi(string);

        histo[v]++;
    }

    for (auto kvp : histo) {
        std::cout << kvp.first << " " << kvp.second << std::endl;
    }

    std::cout << std::endl;
}
