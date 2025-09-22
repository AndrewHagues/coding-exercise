#pragma once

#include "aliases.h"

namespace exercise {

/**
 * @brief Converts each ID number into its corresponding bit pattern for
 * display.
 *
 * @param checksummed_ids The vector of IDs to process.
 *
 * @return An unordered_map of the IDs and their corresponding bit patterns.
 */

BitPatterns create_bit_patterns(const ChecksumIDs& checksummed_ids);

}  // namespace exercise