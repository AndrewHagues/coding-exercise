#pragma once

#include "aliases.h"

namespace exercise {

/**
 * @brief Calculates the 2 digit checksum for each asset ID.
 *
 * @param asset_ids The vector of asset IDs to process.
 *
 * @return A vector of 6 digit ID numbers consisting of the checksum and
 * the original 4 digit asset id.
 */

ChecksumIDs calculate_checksum_id(const AssetIDs& asset_ids);
}  // namespace exercise