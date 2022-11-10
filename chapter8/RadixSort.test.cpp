#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "RadixSort.hpp"
#include "doctest/doctest.h"

namespace chapter8 {
TEST_CASE("Check get digit") {
  CHECK_EQ(get_digit(234, 1), 4);
  CHECK_EQ(get_digit(234, 2), 3);
  CHECK_EQ(get_digit(234, 3), 2);
}

TEST_CASE("Test the sort") {
  std::vector<int> vec {329, 457, 657, 839, 436, 720, 355};
  std::vector<int> expected {329, 355, 436, 457, 657, 720, 839};

  std::vector<int> result = RadixSort(vec, 3);

  CHECK_EQ(result, expected);
}
} // namespace chapter8