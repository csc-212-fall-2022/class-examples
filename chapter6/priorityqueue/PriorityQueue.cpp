#include <stdexcept>
#include <string>
#include <vector>
#include <bits/stdc++.h>

namespace chapter6::priorityqueue {
struct Item {
  int weight;
  std::string item;
};

auto Parent(int idx) -> int { return (idx - 1) / 2; }

auto Left(int idx) -> int { return 2 * idx + 1; }

auto Right(int idx) -> int { return 2 * idx + 2; }

class PriorityQueue {
    private:
    std::vector<Item> heap;
    int heap_size;

    void MaxHeapify(int idx) {
      int largest_index = idx;
      Item largest_value = heap.at(idx);

      int left = Left(idx);
      int right = Right(idx);

      if (left < heap_size && heap.at(left).weight > heap.at(idx).weight) {
        largest_index = left;
        largest_value= heap.at(left);
      }

      if (right < heap_size && heap.at(right).weight > heap.at(idx).weight) {
        largest_index = right;
        largest_value = heap.at(right);
      }

      // swap if we need to
      if (largest_index != idx) {
        heap.at(largest_index) = heap.at(idx);
        heap.at(idx) = largest_value;
      }
    }

    public:
    PriorityQueue() {
      heap = std::vector<Item> {};
      heap_size = 0;
    }

    // return the max weight in the queue
    auto Maximum() -> int {
      if (heap_size > 0) {
        return heap.at(0).weight;
      }

      throw std::underflow_error("Queue is empty!");
    }

    auto ExtractMax() -> Item {
      if (heap_size == 0) {
        throw std::underflow_error("Queue is empty!");
      }

      Item maxItem = heap.at(0);

      // now we need to put someone at index 0 and repair the heap
      heap.at(0) = heap.at(heap_size - 1);
      heap_size--;
      MaxHeapify(0);
      return maxItem;
    }

    void Delete(int index) {
      if (index == heap_size - 1) {
        heap_size --;
      } else {
        // replace with the last element
        heap.at(index) = heap.at(heap_size - 1);
        heap_size --;
        MaxHeapify(index);
      }
    }

    // Here, we're implicitly assuming that all keys are distinct
    void IncreaseKey(int index, int newWeight) {
      int currentWeight = heap.at(index).weight;
      if (newWeight < currentWeight) {
        throw std::runtime_error("Cannot decrease a weight!");
      }
      // update the weight
      heap.at(index).weight = newWeight;

      // repair the heap
      while (index > 0) {
        int parent = Parent(index);
        if (heap.at(parent).weight < heap.at(index).weight) {
          // need to swap with our parent
          Item tmp = heap.at(index);
          heap.at(index) = heap.at(parent);
          heap.at(parent) = tmp;
          index = parent;
        } else {
          // we're placed correctly relative to the parent
          break;
        }
      }
    }

    void Insert(std::string s, int weight) {
      Item item = Item();
      item.item = s;
      item.weight = INT_MIN;

      heap.push_back(item); // we don't need to worry about having space
      heap_size++;

      IncreaseKey(heap.size() -1, weight);
    }
};
} // namespace chapter6::priorityqueue