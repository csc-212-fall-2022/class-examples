#include "MaxHeap.hpp"

namespace chapter6 {
// Return the index of the parent of the element at idx in the backing array
auto Parent(int idx) -> int { return (idx - 2) / 2; }

auto Left(int idx) -> int { return 2 * idx + 1; }

auto Right(int idx) -> int { return 2 * idx + 2; }

void MaxHeapify(MaxHeap &heap, int idx) {
  // remember that we have supposed the left and right subtrees are themselves
  // heaps
  int left_idx = Left(idx);
  int right_idx = Right(idx);

  int largest_idx = idx;
  int largest_value = heap.vec.at(idx);

  if (left_idx < heap.heap_size && heap.vec.at(left_idx) > largest_value) {
    largest_idx = left_idx;
    largest_value = heap.vec.at(left_idx);
  }

  if (right_idx < heap.heap_size && heap.vec.at(right_idx) > largest_value) {
    largest_idx = right_idx;
    largest_value = heap.vec.at(right_idx);
  }

  // now we swap if we need to -- swapping with largest guarantees we maintain
  // the heap property
  if (largest_idx != idx) {
    heap.vec.at(largest_idx) = heap.vec.at(idx);
    heap.vec.at(idx) = largest_value;
    // need to recurse and call MaxHeapify on the index we swapped to
  }
}

void BuildMaxHeap(MaxHeap &heap) {
  // we want to walk backwards through the non-leaf nodes and just call
  // MaxHeapify
  for (int idx = heap.heap_size / 2; idx >= 0; idx--) {
    MaxHeapify(heap, idx);
  }
}


} // namespace chapter6