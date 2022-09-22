#ifndef BLOOMFLITER_H
#define BLOOMFLITER_H

#include <array>
#include <functional>
#include <ostream>
#include <string>
namespace bloomfilter {

class BloomFilter {
private:
  bool *arr_; // this is going to be an array -- we don't know the size at
              // compile time so can't use std::bitset
  uint m_;
  uint k_;
  std::function<uint(std::string)> h1_;
  std::function<uint(std::string)> h2_;

  auto Hash(int, std::string) -> uint;

  friend std::ostream& operator<<(std::ostream &os, const BloomFilter &bloom);

public:
  BloomFilter(uint, uint);
  ~BloomFilter();
  void Add(std::string);
  auto Contains(std::string) -> bool;
};

} // namespace bloomfilter

#endif
