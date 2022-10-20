#include <vector>

namespace chapter6 {

struct MaxHeap {
  std::vector<int> vec;
  int heap_size;
};

void MaxHeapify(MaxHeap &, int idx);

void BuildMaxHeap(MaxHeap &);

auto Parent(int idx) -> int;

auto Left(int idx) -> int;

auto Right(int idx) -> int;
} // namespace c;hapter6