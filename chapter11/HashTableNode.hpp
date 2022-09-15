namespace chapter11 {
template <typename T, typename K> struct Node {
  Node *next;
  T val;
  K key;
};
} // namespace chapter11