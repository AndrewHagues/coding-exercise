#pragma once

#include <string>

#include "aliases.h"

namespace exercise {
/**
 * @brief Reads and validates asset IDs from an input file.
 *
 * @param filename The path (including the filename) of the input file.
 *
 * @return A vector of valid asset IDs read from the file.
 */
AssetIDs read_input(const std::string& filename);
}  // namespace exercise
