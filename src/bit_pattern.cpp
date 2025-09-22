#include "bit_pattern.h"

#include <iostream>
#include <string>
#include <utility>

#include "aliases.h"
#include "constants.h"

// Local function declarations
namespace {

std::pair<bool, std::string> assemble_bit_pattern(const std::string& id);

}  // namespace

namespace exercise {

BitPatterns create_bit_patterns(const ChecksumIDs& checksummed_ids) {
  BitPatterns bit_patterns;
  bit_patterns.reserve(checksummed_ids.size());

  for (const auto& id : checksummed_ids) {
    auto [success, pattern] = assemble_bit_pattern(id);
    if (success) {
      // Extract the asset ID to use as the key
      auto asset_id = id.substr(id.size() - exercise::asset_id_length);
      bit_patterns.emplace(asset_id, pattern);
    }
  }
  return bit_patterns;
}
}  // namespace exercise

namespace {

std::pair<bool, std::string> assemble_bit_pattern(const std::string& id) {
  std::string pattern;
  pattern.reserve(exercise::bit_pattern_size);

  try {
    for (const char& digit : id) {
      pattern += exercise::decimal_bits.at(digit);
    }
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: Invalid digit in ID '" << id << "': " << e.what()
              << std::endl;
    return {false, pattern};
  }
  return {true, pattern};
}
}  // namespace
