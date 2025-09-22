#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace exercise {

using AssetIDs = std::unordered_set<std::string>;
using ChecksumIDs = std::unordered_set<std::string>;
using BitPatterns = std::unordered_map<std::string, std::string>;

}  // namespace exercise