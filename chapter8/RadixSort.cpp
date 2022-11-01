#include "RadixSort.hpp"
#include "CountingSort.hpp"

#include <cmath>
#include <stdexcept>


namespace chapter8 {
// get the d-th digit of n
// d = 1 -> 1s digit
auto get_digit(int n, int d) -> int {
  // divide by 10 to get rid of the lower digits
  for (int i = 1; i < d; i++) {
    n = n / 10;
  }
  return n % 10;
}

auto RadixSort(std::vector<int> vec, int d) -> std::vector<int> {
  // first check that the elements in our vector are of length d
  int upper_bound = std::pow(10, d);     // if d = 1 -> 10
  int lower_bound = std::pow(10, d - 1); // if d = 1 -> 1
  for (int v : vec) {
    if (v < lower_bound || v >= upper_bound) {
      throw std::runtime_error("Values in vector are out of range!");
    }
  }
  std::vector<int> result = vec;
  for (int i = 1; i <= d; i++) {
    std::function<int(int)> func = [&d](int n){ return get_digit(n, d);};
    result = CountingSort(result, 9, func);
  }

  return result;
}

}