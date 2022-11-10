#include <vector>
#include "CountingSort.hpp"

namespace chapter8 {
// Sort the vector A. All elements of A are in the range 0 <= i <= k.
std::vector<int> CountingSort(const std::vector<int> &A, const int &k) {
  int n = A.size(); // n to be 8
  std::vector<int> result;
  std::vector<int> counts;
  for (int i = 0; i <= k; i++) { // make sure that we include an index for the value k
    counts.push_back(0);
  }
  for (int i = 0; i < A.size(); i++) {
    result.push_back(0);
  }
  // next, we count up the occurrences of all elements in A
  for (int el : A) { // iterate over the *actual* elements of the vector, rather than indices
    counts.at(el)++;
  }
  // now, update C with the cumulative sums
  for (int i = 1; i <= k; i++) {
    counts.at(i) = counts.at(i) + counts.at(i - 1);
  }
  // walk backwards through A to construct our final vector
  for (int i = n - 1; i > -1; i--) {
    int target_index =
        counts.at(A.at(i)) - 1; // subtract 1 because we index from 0
    result.at(target_index) = A.at(i);
    counts.at(A.at(i))--;
  }

  return result;
}

// a variant of counting sort that, rather than sorting by the elements A
// directly, sort by func(A[i]).
auto CountingSort(const std::vector<int> &A, const int &k,
                            std::function<int(int)> func) -> std::vector<int> {
  std::vector<int> result;
  result.resize(A.size());
  std::vector<int> counts;
  for (int i = 0; i <= k; i++) {
    counts.push_back(0);
  }

  // next, count up the occurrences (by the key!)
  for (int el: A) {
    int key = func(el);
    counts.at(key)++;
  }

  // make the cumuluative sums
  for (int i = 1 ; i < counts.size(); i++) {
    counts.at(i) = counts.at(i) + counts.at(i-1);
  }

  // walk backwards
  for (int i= A.size() - 1; i > -1; i--) { // NOLINT
    int key = func(A.at(i));
    int target_index = counts.at(key) - 1; // index from 0
    result.at(target_index) = A.at(i); // place the actual value, not the key
    counts.at(key)--;
  }

  return result;
}
}