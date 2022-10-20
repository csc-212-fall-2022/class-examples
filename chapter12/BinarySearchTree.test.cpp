#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "BinarySearchTree.hpp"
#include <array>

using namespace chapter12;

std::array<int,6> values = {4,3,1,2,5,6};

TEST_CASE("In order traversal should produce the insert order") {

    // fail the test so we hopefully see stdout
    CHECK(true);
}
