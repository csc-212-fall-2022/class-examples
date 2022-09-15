#include "HashTableNode.hpp"
#include <functional>
#include <stdexcept>
#include <vector>

namespace chapter11 {
// Why are we implementing in the header file?
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template <typename T, typename K> class ChainedHashMap {
private:
  // vector storing the heads of the linked lists
  std::vector<Node<T, K> *> vec_;
  std::function<int(K)> h_;

  auto GetHead(int idx) -> Node<T,K>* {
      if (idx >= vec_.size()) {
        vec_.resize(idx+1);
      }
      return vec_.at(idx);
  }

public:
  ChainedHashMap<T, K>(std::function<int(K)> h) { h_ = h; }

  auto Search(K key) -> T * {
    int idx = h_(key); // compute which bucket we're in

    // at this point, it's basically the same linked list things
    Node<T, K> *head = GetHead(idx);
    Node<T, K> *curr = head;
    while (curr != nullptr) {
      if (curr->key == key) {
        // remember that we assume the *keys* are unique, even if
        // we allow hash collisions
        return &(curr->val);
      }
      curr = curr->next;
    }
    return nullptr;
  }

  void Insert(K key, T value) {
    int idx = h_(key);

    // again, just a linked list operation
    auto *node = new Node<T, K>();
    node->key = key;
    node->val = value;

    node->next = GetHead(idx); // stick it on the front of the list
    vec_[idx] = node;
  }

  void Delete(K key) {
    // effectively search + a LL delete
    int idx = h_(key);

    auto prev = GetHead(idx);
    if (prev->key == key) {
      // I found it at the beginning!
      vec_[idx] = prev->next; // drop it from our linked list
      delete prev;
      return;
    }

    Node<T, K> *curr = prev->next;
    while (curr != nullptr) {
      if (curr->key == key) {
        // we're going to drop curr
        prev->next = curr->next; // skip over curr in the list
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
    throw std::runtime_error("The key wasn't found in the map!");
  }
};
} // namespace chapter11
