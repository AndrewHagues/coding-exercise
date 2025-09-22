#include "read_input.h"

#include <gtest/gtest.h>

#include <fstream>
#include <string>
#include <vector>

#include "aliases.h"

TEST(ReadInputTest, ValidFile) {
  const std::string test_filename = "ValidFile_test.txt";
  std::ofstream test_file(test_filename);
  test_file << "1234\n";
  test_file << "5678  \n";
  test_file << "  6666\n";
  test_file.close();

  exercise::AssetIDs expected_asset_ids = {"1234", "5678", "6666"};

  exercise::AssetIDs asset_ids = exercise::read_input(test_filename);
  EXPECT_EQ(asset_ids, expected_asset_ids);
}

TEST(ReadInputTest, ContainsInvalidIDs) {
  const std::string test_filename = "ContainsInvalidIDs_test.txt";
  std::ofstream test_file(test_filename);
  test_file << "1234 \n";
  test_file << " 56x8 \n";
  test_file << " \n";
  test_file << "  6666\n";
  test_file.close();

  exercise::AssetIDs expected_asset_ids = {"1234", "6666"};

  exercise::AssetIDs asset_ids = exercise::read_input(test_filename);
  EXPECT_EQ(asset_ids, expected_asset_ids);
}