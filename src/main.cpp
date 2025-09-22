#include <string>

#include "aliases.h"
#include "bit_pattern.h"
#include "checksum.h"
#include "constants.h"
#include "lodepng.h"
#include "read_input.h"
#include "write_png_images.h"

int main(int argc, char* argv[]) {
  const std::string input_file((argc == 1) ? exercise::default_input_filename
                                           : argv[1]);

  const exercise::AssetIDs asset_ids = exercise::read_input(input_file);

  const exercise::ChecksumIDs checksummed_ids =
      exercise::calculate_checksum_id(asset_ids);

  const exercise::BitPatterns bit_patterns =
      exercise::create_bit_patterns(checksummed_ids);

  exercise::write_png_images(bit_patterns);

  return 0;
}
