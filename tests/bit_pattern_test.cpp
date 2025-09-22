#include "bit_pattern.h"

#include <gtest/gtest.h>

#include "aliases.h"

TEST(BitPatternTest, ValidID) {
  exercise::ChecksumIDs checksummed_ids = {"561337"};
  exercise::BitPatterns expected = {
      {"1337", "110101011111001101000010110101101101011001000110"}};
  auto result = exercise::create_bit_patterns(checksummed_ids);
  EXPECT_EQ(result, expected);
}

TEST(BitPatternTest, InvalidID) {
  exercise::ChecksumIDs checksummed_ids = {"561337", "X61337"};
  exercise::BitPatterns expected = {
      {"1337", "110101011111001101000010110101101101011001000110"}};
  auto result = exercise::create_bit_patterns(checksummed_ids);
  EXPECT_EQ(result, expected);
}
