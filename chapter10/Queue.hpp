//
// Created by csar on 9/5/22.
//

#ifndef CLASS_EXAMPLES_QUEUE_HPP
#define CLASS_EXAMPLES_QUEUE_HPP

namespace chapter10 {

class Queue {
private:
  int head_;
  int tail_;
  int capacity_;
  int *arr_; // NOTE: Would be safer to use a vector here, but I want the fixed
             // capacity intentionally
public:
  Queue(int);
  ~Queue();
  void enqueue(int);
  int dequeue();
};

} // namespace chapter10

#endif // CLASS_EXAMPLES_QUEUE_HPP
