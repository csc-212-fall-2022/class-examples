namespace chapter10 {

struct Node {
  int val;
  Node *next;

  //  https://en.cppreference.com/w/cpp/language/constructor
  Node() : val(0), next(nullptr){};
  Node(int x) : val(x), next(nullptr){};
  Node(int x, Node *next) : val(x), next(next){};
};

// LeetCode #83
auto DedupeLinkedList(Node *head) -> Node * {
  if (!head) {
    return head;
  }
  Node *prev = head;
  Node *cur = head->next;

  while (prev != nullptr && cur != nullptr) {
    if (prev->val == cur->val) {
      // drop cur and advance
      prev->next = cur->next;
      cur = cur->next;
    } else {
      // we need to update prev
      prev->next = cur;
      prev = cur;
      cur = cur->next;
    }
  }
  return head;
}

}; // namespace chapter10
