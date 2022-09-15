#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "ChainedHashTable.hpp"
#include "doctest/doctest.h"

using namespace chapter11;

TEST_CASE("Test adding an element") {
  std::function<int(int)> h = [](int key) { return key % 3; };
  ChainedHashMap<int, int> map = ChainedHashMap<int, int>(h);

  map.Insert(3, 3);
  int *found = map.Search(3);
  CHECK(found != nullptr);
  int found_value;
  found_value = *found;
  CHECK(found_value == 3);
}