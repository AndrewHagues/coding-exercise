#include "checksum.h"

#include <algorithm>
#include <format>

#include "aliases.h"
#include "constants.h"

// Local function declarations
namespace {

std::string compute_checksum(const std::string& input_code);

}  // namespace

namespace exercise {

ChecksumIDs calculate_checksum_id(const AssetIDs& asset_ids) {
  ChecksumIDs checksummed_asset_ids(asset_ids.size());

  std::transform(
      asset_ids.cbegin(), asset_ids.cend(),
      std::inserter(checksummed_asset_ids, checksummed_asset_ids.end()),
      compute_checksum);
  return checksummed_asset_ids;
}
}  // namespace exercise

namespace {

std::string compute_checksum(const std::string& input_code) {
  int weight = 1;
  int weighted_sum = 0;

  for (const auto& c : input_code) {
    int digit = c - '0';
    weighted_sum += digit * weight;
    weight *= 10;
  }

  int checksum = weighted_sum % exercise::checksum_modulo;

  // Format checksum as two digits, padding with leading zero if necessary
  std::string checksum_str = std::format("{:02}", checksum) + input_code;
  return checksum_str;
}

}  // namespace