namespace chapter10 {
struct Node {
  int value;
  Node *next;
  Node *prev;
};

class SentinelLinkedList {
private:
  Node sentinel;

public:
  SentinelLinkedList() {
    sentinel = Node();
    sentinel.value = 0;
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;
  }

  void Insert(int n) {
    Node *toInsert = new Node();
    toInsert->value = n;

    // I'm going to insert between sentinel (which definitely exists) and
    // sentinel.next (which might itself be the sentinel)

    sentinel.next->prev =
        toInsert; // first element was sentinel.next and it needs to point back
                  // to our newly inserted element
    toInsert->next =
        sentinel
            .next; // our inserted element points forward to the first element
    toInsert->prev = &sentinel;
    sentinel.next = toInsert;

    // More confusing original version
    // toInsert->next = sentinel.next;
    // toInsert->prev = &sentinel;
    // sentinel.next = toInsert;

    // toInsert->next->prev = toInsert;
  }

  void Delete(Node *node) {
    // we don't need to worry about nullptr because at worst, we end up poiting
    // to the sentinel when we hit the ends of the list
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // clean up the node pointer (probably where we called delete)
  }
};
} // namespace chapter10