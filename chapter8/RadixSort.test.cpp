#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "RadixSort.hpp"
#include "doctest/doctest.h"

namespace chapter8 {
TEST_CASE("Check get digit") {
  CHECK_EQ(get_digit(234, 1), 4);
  CHECK_EQ(get_digit(234, 2), 3);
  CHECK_EQ(get_digit(234, 3), 2);
}
} // namespace chapter8