#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Queue.hpp"
#include "doctest/doctest.h"

using namespace chapter10;

TEST_CASE("Test enqueue and deque simple") {
  Queue queue = Queue(5);
  queue.enqueue(3);
  queue.enqueue(1);

  CHECK(queue.dequeue() == 3);
}

TEST_CASE("Test overflow on insert") {
  Queue queue = Queue(2);
  queue.enqueue(1);
  queue.enqueue(2);

  CHECK_THROWS(queue.enqueue(3));
}

TEST_CASE("Test indices looping round") {
  Queue queue = Queue(2);

  queue.enqueue(1);
  queue.enqueue(2);

  CHECK(queue.dequeue() == 1);

  queue.enqueue(3);

  CHECK(queue.dequeue() == 2);
  CHECK(queue.dequeue() == 3);
  CHECK_THROWS(queue.dequeue());
}

TEST_CASE("Overflow when we hit head") {
  Queue queue = Queue(2);

  queue.enqueue(1);
  queue.enqueue(2);

  CHECK(queue.dequeue() == 1);
  queue.enqueue(3);

  // No room!
  CHECK_THROWS(queue.enqueue(4));
}