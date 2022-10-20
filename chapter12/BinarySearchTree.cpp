#include "BinarySearchTree.hpp"
#include <iostream>

namespace chapter12 {
BinarySearchTree::BinarySearchTree(TreeNode *r) { root = r; }

void BinarySearchTree::Insert(int n) {
  // first things first, do we have a root?
  if (root == nullptr) {
    root = new TreeNode();
    root->value = n;
  } else {
    // Find the node below which we will insert
    TreeNode *parent = nullptr;
    TreeNode *curr = root;
    while (curr != nullptr) {
      parent = curr;
      if (n < curr->value) { // need to go left
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }
    auto *node = new TreeNode();
    node->value = n;
    // we could potentially keep track of whether we stepped left/right with a
    // variable
    if (n < parent->value) {
      std::cout << "Inserting " << n << " as left child of " << parent->value << std::endl;
      // insert as a left child
      parent->left = node;
    } else {
      std::cout << "Inserting " << n << " as right child of " << parent->value << std::endl;
      // insert as a right child;
      parent->right = node;
    }
  }
}

auto BinarySearchTree::Search(int n) -> bool {
  TreeNode *curr = root;

  while (curr != nullptr) {
    if (curr->value == n) {
      // found it!
      return true;
    }
    // otherwise figure out which direction to go
    if (n < curr->value) {
      // step left
      curr = curr->left;
    } else {
      // step right
      curr = curr->right;
    }
  }
  return false;
}

// recursive version of Search
auto Search(TreeNode *root, int n) -> bool {
  if (root == nullptr) {
    return false;
  }
  if (root->value == n) {
    // found it
    return true;
  }

  if (n < root->value) {
    return Search(root->left, n);
  }

  else {
    return Search(root->right, n);
  }
}

void PrintInOrder(TreeNode *root) {
  // too hard to get a newline at the end, I think--you have to have a helper
  // function;
  if (root != nullptr) {
    // print the left tree
    PrintInOrder(root->left);
    std::cout << root->value << " ";
    PrintInOrder(root->right);
  }
  // otherwise, do nothing, we're done
}

} // namespace chapter12
