#include <iostream>
#include <stdexcept>

namespace chapter10 {

struct DLNode {
  int value;
  DLNode *next;
};

class SLinkedList {
private:
  DLNode *head;

public:
  SLinkedList(DLNode* node) {
    head = node;
  }

  DLNode* Insert(int n) {
    auto *toInsert = new DLNode();
    std::cout << "Inserting " << n << "\n";
    toInsert->value = n;
    toInsert->next = head;
    head = toInsert;
    return toInsert;
  }

  void Delete(DLNode* node) {
    if (head == node) {
      std::cout << "Found at head. Deleting " << node->value << "\n";
      head = node->next;
    } else {
      // our ultimate goal is to have prev(node)->next = node->next
      DLNode* prev = head;
      DLNode* curr = head->next;
      
      while(curr != nullptr && curr != node) {
        std::cout << "Prev value is: " << prev->value << "\n";
        std::cout << "Curr value is: " << curr->value << "\n";
        // we haven't found who we're trying to remove
        prev = curr;
        curr = curr->next;
      }


      // the loop ended -- either we hit the end of the list, or we found node
      if (curr == nullptr) {
        // we hit the end of the list
        throw std::runtime_error("Node wasn't in the list!");
      }

      // we found the node -> it's curr
      prev->next = node->next;
      std::cout << "Deleting " << node->value << "\n";
      delete node;
    }
  }

  // Find the first node in the list whose value is n
  auto Find(int n) -> DLNode* {
    DLNode* curr = head;
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

  chapter10::DLNode* node1 = new chapter10::DLNode();
  node1->value =1;
  node1->next = nullptr;

  chapter10::SLinkedList linked_list = chapter10::SLinkedList(node1);
  linked_list.Insert(2);
  linked_list.Insert(3);

  // Deleting the last element of the list means deleting node1 because we insert at the front!
  linked_list.Delete(node1);
}