#include <vector>
#include <random>

namespace chapter7 {


// return the index where the pivot ends up
auto Partition(std::vector<int> &A, int p, int r) -> int { // NOLINT
  // remember: p and r are the first and last indices (i.e. they're in the
  // array!)
  int pivot = A.at(r);
  int lower_segment_end = p - 1;
  // now process each element besides the pivot
  for (int j = p; j < r; j++) {
    // if A[j] > pivot, we belong in the upper region and we just extend (i.e.
    // do nothing here) on the other hand, if <= pivot, we need to swap it into
    // place
    if (A.at(j) <= pivot) {
      // if this is the first element of the lower segment, it'll swap into indo
      // p setting lower_segment_end = p-1 just means we don't need to handle
      // this case separately
      lower_segment_end++; // this is the index we'll swap A[j] into
      int tmp = A.at(j);
      A.at(j) = A.at(lower_segment_end);
      A.at(lower_segment_end) = tmp;
    }
  }
  // now that we've made the upper and lower partitions, put the pivot in the
  // right place
  int pivot_index = lower_segment_end + 1;
  int tmp = A.at(r);
  A.at(r) = A.at(pivot_index);
  A.at(pivot_index) = tmp;
  return pivot_index;
}

auto RandomizedPartition(std::vector<int> &A, int p, int r) -> int { // NOLINT
    std::uniform_int_distribution<int> distribution(p,r);
    std::default_random_engine generator;
    // pick a random pivot and swap it to be the last
    int pivot_index = distribution(generator);
    int tmp = A.at(r);
    A.at(r) = A.at(pivot_index);
    A.at(pivot_index) = tmp;
    return Partition(A, p, r);
}

void RandomizedQuicksort(std::vector<int> &A, int p, int r){ // NOLINT
    if (p < r) {
        int q = RandomizedPartition(A, p, r);
        RandomizedQuicksort(A, p, q-1);
        RandomizedQuicksort(A, q+1, r);
    }
}

void Quicksort(std::vector<int> &A, int p, int r) { // NOLINT
  if (p < r) {
    int q = Partition(A, p, r);
    Quicksort(A, p, q - 1);
    Quicksort(A, q + 1, r);
  }
  // otherwise one element array, already sorted
}

} // namespace chapter7