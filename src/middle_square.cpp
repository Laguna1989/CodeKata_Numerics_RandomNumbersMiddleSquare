#include "middle_square.hpp"
#include <iomanip>
#include <sstream>

std::string get_middle_string(std::string const& input_string, size_t new_string_length)
{
    size_t const input_string_length = input_string.length();
    size_t const offset = input_string_length / 2 - new_string_length / 2;

    return input_string.substr(offset, new_string_length);
}

std::uint32_t middle_square(std::uint32_t initial, std::size_t number_of_digits)
{
    std::uint32_t const num = initial * initial;

    std::stringstream stream;

    stream << std::setw(number_of_digits) << std::setfill('0') << std::to_string(num);

    return std::stoi(get_middle_string(stream.str(), number_of_digits / 2));
}
