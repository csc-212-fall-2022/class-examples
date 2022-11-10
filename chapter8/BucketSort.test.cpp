#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "BucketSort.hpp"
#include "doctest/doctest.h"

namespace chapter8 {
TEST_CASE("Test insertion sort") {
  std::vector<double> vec{2.0, 1.0, 3.0};
  InsertionSort(vec);

  std::vector<double> expected{1.0, 2.0, 3.0};
  CHECK_EQ(vec, expected);
}

TEST_CASE("Test bucket sort") {
  std::vector<double> vec{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
  std::vector<double> expected{0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94};

  auto result = BucketSort(vec);

  CHECK_EQ(vec, expected);
}
} // namespace chapter8