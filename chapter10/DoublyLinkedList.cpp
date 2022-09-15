#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace chapter10 {
struct DLNode {
  int value;
  DLNode *next;
  DLNode *prev;
};

class DLinkedList {
private:
  DLNode *head;

public:
  DLinkedList() {
    head = new DLNode();
    head->next = nullptr;
    head->prev = nullptr;
  }

  DLNode *Insert(int n) {
    auto *toInsert = new DLNode();
    std::cout << "Inserting " << n << "\n";
    toInsert->value = n;
    toInsert->next = head;
    // now because we're doubly linked, we need to update prev too
    toInsert->prev = nullptr;
    head->prev = toInsert;

    head = toInsert;
    return toInsert;
  }

  void Delete(DLNode *node) {
    if (node == head) {
      head = node->next;
      head->prev = nullptr;
    }

    // as long as node->prev exists, we're done
    // link node's prev and next to each other
    node->prev->next = node->next;
    // guard against the case where node was last
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }
    delete node; // debatable whether this is a good idea
  }

  // Find the first node in the list whose value is n
  auto Find(int n) -> DLNode * {
    DLNode *curr = head;
    while (curr != nullptr) {
      if (curr->value == n) {
        // we found it!
        return curr;
      }
      curr = curr->next;
    }
    return nullptr;
  }
};
} // namespace chapter10

auto main() -> int {

  std::cout << "Hello world!";

  chapter10::DLNode *node1 = new chapter10::DLNode();
  node1->value = 1;
  node1->next = nullptr;

  chapter10::SLinkedList linked_list = chapter10::SLinkedList(node1);
  linked_list.Insert(2);
  linked_list.Insert(3);

  // Deleting the last element of the list means deleting node1 because we
  // insert at the front!
  linked_list.Delete(node1);
}