#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace exercise {

inline constexpr std::string_view default_input_filename = "test.txt";
inline constexpr int asset_id_length = 4;
inline constexpr int checksum_modulo = 97;
inline const std::unordered_map<char, std::string> decimal_bits{
    {'0', "01110111"}, {'1', "01000010"}, {'2', "10110110"}, {'3', "11010110"},
    {'4', "11000011"}, {'5', "11010101"}, {'6', "11110101"}, {'7', "01000110"},
    {'8', "11110111"}, {'9', "11010111"},
};
inline constexpr int bit_pattern_size = 48;
inline constexpr int png_image_width = 256;
inline constexpr int png_image_height = 1;
inline constexpr std::string_view output_file_extension = ".png";

}  // namespace exercise