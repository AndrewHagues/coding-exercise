#include "checksum.h"

#include <gtest/gtest.h>

#include "aliases.h"

TEST(ChecksumTest, ChecksumTest) {
  exercise::AssetIDs asset_ids = {"1337"};
  exercise::ChecksumIDs expected = {"561337"};
  auto result = exercise::calculate_checksum_id(asset_ids);
  EXPECT_EQ(result, expected);
}
