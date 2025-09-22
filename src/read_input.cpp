#include "read_input.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>

#include "aliases.h"
#include "constants.h"

// Local function declarations
namespace {

std::pair<bool, std::string> get_asset_id(const std::string& line);

}  // namespace

namespace exercise {

AssetIDs read_input(const std::string& filename) {
  AssetIDs asset_ids;
  std::ifstream file(filename);
  std::string line;

  while (std::getline(file, line)) {
    auto [success, asset_id] = get_asset_id(line);
    if (success) {
      asset_ids.insert(asset_id);
    } else {
      std::cerr << "Warning: Invalid asset ID: '" << line << std::endl;
    }
  }
  return asset_ids;
}

}  // namespace exercise

namespace {

std::pair<bool, std::string> get_asset_id(const std::string& line) {
  // Valid asset IDs consist solely of digits of predefined length
  std::string pattern_str =
      "^\\s*(\\d{" + std::to_string(exercise::asset_id_length) + "})\\s*$";
  std::regex pattern(pattern_str);

  std::smatch match;
  if (std::regex_match(line, match, pattern)) {
    return {true, match[1].str()};
  }
  return {false, ""};
}

}  // namespace
