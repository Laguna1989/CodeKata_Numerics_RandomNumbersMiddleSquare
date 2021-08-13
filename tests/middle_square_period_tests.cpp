#include "middle_square.hpp"
#include <gtest/gtest.h>

TEST(MiddleSquarePeriodTest, PeriodForNDigits)
{
    for (int N = 2; N != 13; ++N) {
        int counter_sum = 0;
        int min = 9999;
        int max = 0;

        int max_start_seed = 100;
        for (auto i = 0U; i != max_start_seed; ++i) {
            std::uint32_t seed = i;
            std::set<std::uint32_t> already_visited;

            int counter = 0;

            while (true) {
                if (already_visited.count(seed)) {
                    break;
                }
                already_visited.insert(seed);

                seed = middle_square(seed, N);
                counter++;
            }
            counter_sum += counter;
            if (counter < min) {
                min = counter;
            }
            if (counter > max) {
                max = counter;
            }
        }

        std::cout << N << " " << static_cast<double>(counter_sum) / max_start_seed << " " << min
                  << " " << max << std::endl;
    }
}
