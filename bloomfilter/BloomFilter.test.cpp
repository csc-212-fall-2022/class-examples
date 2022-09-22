#include <sstream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "BloomFilter.hpp"
#include "doctest/doctest.h"

using namespace bloomfilter;

TEST_CASE("Initially we should be empty") {
  BloomFilter bloom = BloomFilter(10, 3);
  CHECK_FALSE(bloom.Contains("hello"));
}

TEST_CASE("Test adding an element") {
  BloomFilter bloom = BloomFilter(10, 3);
  bloom.Add("hello");
  CHECK(bloom.Contains("hello"));
}

TEST_CASE("Test contents") {
    std::stringstream ss;
    BloomFilter bloom = BloomFilter(10, 3);
    bloom.Add("Foo");
    ss << bloom;
    std::string before = ss.str();

    WARN(before == "");

}
