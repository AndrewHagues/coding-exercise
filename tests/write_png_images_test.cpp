#include "write_png_images.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "aliases.h"
#include "lodepng.h"  // Make lodepng API visible

namespace {

std::vector<unsigned char> get_png_data(const std::string& filename) {
  std::vector<unsigned char> image;
  unsigned width = 0, height = 0;
  unsigned error = lodepng::decode(image, width, height, filename);
  EXPECT_EQ(0u, error) << "Error decoding PNG file: " << filename << ": "
                       << lodepng_error_text(error);
  if (error) {
    return {};  // Ensure we don't propagate garbage on failure
  }
  return image;
}

}  // namespace

TEST(WritePNGImagesTest, WritePNGImages) {
  exercise::BitPatterns input_bit_pattern = {
      {"1337", "110101011111010101000010110101101101011001000110"}};
  exercise::write_png_images(input_bit_pattern);
  std::vector<unsigned char> expected_png_data =
      get_png_data(std::string(TEST_DATA_DIR) + "/expected.png");
  std::vector<unsigned char> actual_png_data = get_png_data("1337.png");
  EXPECT_EQ(expected_png_data, actual_png_data);
};
