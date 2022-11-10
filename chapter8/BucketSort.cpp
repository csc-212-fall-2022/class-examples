#include "BucketSort.hpp"
#include <cmath>

namespace chapter8 {
void InsertionSort(std::vector<double> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    int j = i - 1;
    while (j > 0 && vec.at(j - 1) > vec.at(j)) {
      // swap them
      double tmp = vec.at(j);
      vec.at(j) = vec.at(j - 1);
      vec.at(j - 1) = tmp;
      j--;
    }
  }
}

auto BucketSort(std::vector<double> A) -> std::vector<double> {
  int n = A.size(); // NOLINT
  std::vector<std::vector<double>> buckets;
  buckets.resize(A.size());
  for (int i = 0; i < n; i++) {
    int index = std::floor(n * A.at(i));
    buckets.at(index).push_back(A.at(i));
  }

  for (int i = 0; i < n; i++) {
    std::vector<double> bucket = buckets.at(i);
    // TODO: We're not sorting in place! What have I done wrong?
    InsertionSort(bucket);
    buckets.at(i) = bucket;
  }

  std::vector<double> result;
  for (auto bucket : buckets) {
    for (auto el : bucket) {
      result.push_back(el);
    }
  }

  return result;
}
} // namespace chapter8