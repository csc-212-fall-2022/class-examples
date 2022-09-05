//
// Created by csar on 9/5/22.
//

#include "Queue.hpp"
#include <iostream>
#include <stdexcept>

namespace chapter10 {
Queue::Queue(int capacity) {
  capacity_ = capacity;
  head_ = -1;
  tail_ = -1;
  arr_ = new int[capacity];
}

Queue::~Queue() { delete[] arr_; }

void Queue::enqueue(int n) {
  // first need to check for the case where the queue is empty
  if (head_ == -1) {
    arr_[0] = n;
    head_ = 0;
    tail_ = 0;
  } else {
    int idx = (tail_ + 1) % capacity_;
    if (idx == head_) {
      throw std::overflow_error("Queue is full!");
    }
    arr_[idx] = n;
    tail_ = idx;
  }
}

auto Queue::dequeue() -> int {
  if (tail_ < 0) {
    throw std::underflow_error("Queue is empty!");
  }
  // dequeue should be easier--we need to check for the case where we've emptied
  // the queue, but otherwise we decrement and update
  if (head_ == tail_) {
    int val = arr_[tail_];
    head_ = -1;
    tail_ = -1;
    return val;
  }
  int val = arr_[head_];
  head_ = (head_ + 1) % capacity_;
  return val;
}

} // namespace chapter10