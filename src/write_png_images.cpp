#include "write_png_images.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "aliases.h"
#include "constants.h"
#include "lodepng.h"

// Local function declarations
namespace {

lodepng::State setup_lodepng_state();
std::vector<unsigned char> construct_png_data(const std::string& bit_pattern);
void write_png_file(const std::string& filename,
                    const std::vector<unsigned char>& raw_data,
                    lodepng::State& state);

}  // namespace

namespace exercise {

void write_png_images(const BitPatterns& bit_patterns) {
  lodepng::State state = setup_lodepng_state();

  for (const auto& [asset_id, pattern] : bit_patterns) {
    // print pattern for debugging
    std::vector<unsigned char> png_data = construct_png_data(pattern);
    std::string filename =
        asset_id + std::string(exercise::output_file_extension);
    write_png_file(filename, png_data, state);
  }

  lodepng_state_cleanup(&state);
}
}  // namespace exercise

namespace {

lodepng::State setup_lodepng_state() {
  lodepng::State state;
  lodepng_state_init(&state);

  // The input has a bitdepth of 8 (1 unsigned char per pixel)
  state.info_raw.colortype = LCT_PALETTE;
  state.info_raw.bitdepth = 8;

  // Output image has a bitdepth of 1 (1 bit per pixel)
  state.info_png.color.colortype = LCT_PALETTE;
  state.info_png.color.bitdepth = 1;

  // Define palette: index 0 = white, index 1 = black
  lodepng_palette_add(&state.info_raw, 255, 255, 255, 255);
  lodepng_palette_add(&state.info_raw, 0, 0, 0, 255);

  lodepng_palette_add(&state.info_png.color, 255, 255, 255, 255);
  lodepng_palette_add(&state.info_png.color, 0, 0, 0, 255);

  return state;
}

std::vector<unsigned char> construct_png_data(const std::string& bit_pattern) {
  std::string png_pattern(exercise::png_image_width, '0');
  png_pattern.replace(8, exercise::bit_pattern_size, bit_pattern);

  std::vector<unsigned char> png_data(exercise::png_image_width);
  std::transform(png_pattern.begin(), png_pattern.end(), png_data.begin(),
                 [](char c) { return static_cast<unsigned char>(c - '0'); });

  return png_data;
}

void write_png_file(const std::string& filename,
                    const std::vector<unsigned char>& raw_data,
                    lodepng::State& state) {
  std::vector<unsigned char> image_data;
  unsigned error =
      lodepng::encode(image_data, raw_data, exercise::png_image_width,
                      exercise::png_image_height, state);

  if (error) {
    std::cerr << "Encoder error " << error << ": " << lodepng_error_text(error)
              << std::endl;
    return;
  }

  lodepng::save_file(image_data, filename);
  std::cout << "Created image file: " << filename << std::endl;
}

}  // namespace
