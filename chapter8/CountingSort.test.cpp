#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "CountingSort.hpp"

namespace chapter8 {
  TEST_CASE("The example") {
    std::vector<int> vec {2,5,3,0,2,3,0,3};
    std::vector<int> expected {0,0,2,2,3,3,3,5};

    std::vector<int> result = CountingSort(vec, 5);
    CHECK_EQ(result, expected);
  }

  TEST_CASE("Sort by digit") {
    std::vector<int> vec {329, 457, 657, 839, 436, 720, 355};
    std::vector<int> expected {720, 355, 436, 457, 657, 329, 839};

    // anonymous function! (lambda) (Python: lambda x: x % 10; Java: x -> x % 10)
    std::function<int(int)> ones_digit = [](int n) {return n % 10;};

    std::vector<int> result = CountingSort(vec, 9, ones_digit);

    CHECK_EQ(result, expected);
  }
}
