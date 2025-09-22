#pragma once

#include "aliases.h"

namespace exercise {

/**
 * @brief Constructs PNG images from the provided bit patterns.
 *
 * @param bit_patterns unordered_map of the IDs and their corresponding bit
 * patterns.
 *
 */
void write_png_images(const BitPatterns& bit_patterns);
}  // namespace exercise