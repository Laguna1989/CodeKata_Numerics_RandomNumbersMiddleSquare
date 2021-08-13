#ifndef MIDDLE_SQUARE_HPP
#define MIDDLE_SQUARE_HPP

#include <cstddef>
#include <cstdint>
#include <string>

std::string get_middle_string(std::string const& input_string, size_t new_string_length);

std::uint32_t middle_square(std::uint32_t initial, std::size_t number_of_digits = 8);

#endif // MIDDLE_SQUARE_HPP
