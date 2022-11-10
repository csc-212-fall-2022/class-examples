#ifndef CLASS_EXAMPLES_DIGRAPH_HPP
#define CLASS_EXAMPLES_DIGRAPH_HPP

#include "Graph.hpp" // for Color

namespace chapter22 {

struct DVertex {
  int name;
  Color state;
  int d; // discovery timestamp
  int f; // finish processing timestamp
  int pred;

  DVertex(int n) {
    name = n;
    state = WHITE;
    d = INT_MAX
    f = INT_MAX
    pred = INT_MIN
  }
};


class Digraph {
private:
  std::unordered_map<int, DVertex> vertices;
  std::unordered_map<int, std::vector<DVertex>> adjancency_list;

public:
  Digraph(std::unordered_map<int, DVertex>, std::unordered_map<int, std::vector<DVertex>>);

  void depthFirstSearch();

  void dfsVisit(DVertex &v, int &time);
};

} // namespace chapter22

#endif // CLASS_EXAMPLES_DIGRAPH_HPP
