#include <vector>
#include "MaxHeap.hpp"

namespace chapter6 {
    void HeapSort(std::vector<int> &vec) {
        // we're going to sort this vector, so stick it in a heap
        MaxHeap heap = MaxHeap();
        heap.vec = vec;
        heap.heap_size = vec.size();

        // actually make our heap a heap
        BuildMaxHeap(heap);

        // now we sort
        for (int i = 0; i < vec.size() - 1; i++) {
            // swap vec[0] with vec[heap_size -1] -- heap size decreases each time and we do this vec.size - 1 times
            // until we run out of things to swap
            int tmp = heap.vec.at(0);
            heap.vec.at(0) = heap.vec.at(heap.heap_size - 1); // last index in the heap is heap_size - 1
            heap.vec.at(heap.heap_size - 1) = tmp;
            heap.heap_size--;
            // repair our heap
            MaxHeapify(heap, 0);
        }
    }

    void InPlaceHeapSort(std::vector<int> &vec) {

    }
}