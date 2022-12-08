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
    d = INT_MAX;
    f = INT_MAX;
    pred = INT_MIN;
  }
};

class Digraph {
private:
  std::unordered_map<int, DVertex> vertices;
  std::unordered_map<int, std::vector<DVertex>> adjancency_list;

  void topSortVisit(DVertex &v, int &time, std::deque<DVertex> &top_sort);

public:
  Digraph(std::unordered_map<int, DVertex>, std::unordered_map<int, std::vector<DVertex>>);

  void depthFirstSearch();

  void dfsVisit(DVertex &v, int &time);

  void depthFirstSearchIter();

  auto dfsWithOrder(std::vector<int>) -> std::set<std::set<DVertex>>;

  auto TopologicalSort() -> std::deque<DVertex>;

  auto Transpose() -> Digraph;

  auto StronglyConnectedComponents() -> std::set<std::set<DVertex>>;

  void dfsComponentVisit(DVertex, std::set<DVertex>&);
};

} // namespace chapter22

#endif // CLASS_EXAMPLES_DIGRAPH_HPP
