#include "BinarySearchTree.hpp"
#include <array>
#include <iostream>

using namespace chapter12;

int main() {

  std::array<int, 6> values = {4, 3, 1, 2, 5, 6};
  // this is a bit hacky, but we only implemented insert on the class
  auto *root = new TreeNode();
  root->value = 4;
  auto tree = BinarySearchTree(root);

  // skip inserting 4 again
  for (int i = 1; i < 6; i++) {
    tree.Insert(values.at(i));
  }

  // now let's see what happens when we call PrintInOrder

  PrintInOrder(root);
  return 0;
}
