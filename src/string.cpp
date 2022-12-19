#include "utils/string.h"

namespace cc {

std::string Trim(const std::string& input) {
  auto check_non_space = [](unsigned char character) {
    return !std::isspace(character);
  };

  auto first_non_space =
      std::find_if(input.begin(), input.end(), check_non_space);
  auto last_non_space =
      std::find_if(input.rbegin(), input.rend(), check_non_space).base();

  return std::string{first_non_space, last_non_space};
}

}  // namespace cc
