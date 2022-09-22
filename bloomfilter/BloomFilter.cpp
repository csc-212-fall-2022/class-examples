#include "BloomFilter.hpp"
#include <algorithm>
#include <functional>
#include <string>
namespace bloomfilter {

auto operator<<(std::ostream &os, BloomFilter const &bloom) -> std::ostream & {
  os << "|";
  for (int i = 0; i < bloom.m_; i++) {
    uint elt;
    if (bloom.arr_[i]) {
      elt = 1;
    } else {
      elt = 0;
    }
    os << " " << elt << " |";
  }
  return os;
};

// FNV Hash function: https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
auto fnv_hash(std::string s) -> uint {
  const uint fnv_prime = 37;
  uint hash = 74; // some starting value -- just pick something
  // shiny modern for loop!
  for (char c : s) {
    hash *= fnv_prime;
    hash ^= c; // XOR on the bits
  }
  return hash;
}

// Python: foo(m=12, k=5)
// The "right" C++ thing is to pass a struct
BloomFilter::BloomFilter(uint m, uint k) { // NOLINT
    m_ = m;
    k_ = k;
    arr_ = new bool[m_];
    // set up our hash functions
    h1_ = fnv_hash;
    h2_ = std::hash<std::string>{};
}

BloomFilter::~BloomFilter() { delete[] arr_; }

auto BloomFilter::Hash(int i, std::string s) -> uint {
    // make sure we mod to land in a bucket that actually exists
    return (h1_(s) + i * h2_(s)) % m_;
}

void BloomFilter::Add(std::string s) {
    // for each of our hash functions (remember there are k), set the bit
    for (int i = 0; i < k_; i++) {
        uint idx = Hash(i, s);
        arr_[idx] = true;
    }
}

auto BloomFilter::Contains(std::string s) -> bool {
    // loop through our hash functions, if a bit is not set, we're not in the set
    for (int i = 0; i < k_; i++) {
        uint idx = Hash(i,s);
        if (!arr_[idx]) {
            return false;
        }
    }
    // every bit was set
    return true;
}

} // namespace bloomfilter
