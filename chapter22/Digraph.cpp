//
// Created by csar on 11/10/22.
//

#include "Digraph.hpp"

namespace chapter22 {
Digraph::Digraph(std::unordered_map<int, DVertex> vertices,
                 std::unordered_map<int, std::vector<DVertex>> adjacency_list) {
  this->vertices = vertices;
  this->adjancency_list = adjacency_list;
}

void Digraph::depthFirstSearch() {
  // all vertices are white (undiscovered)
  // predecessor is INT_MIN (i.e. undefined)
  int time = 0;
  for (auto &[n, v] : vertices) {
    if (v.state == WHITE) {
      // we just discovered v
      dfsVisit(v, time);
    }
  }

}

void Digraph::dfsVisit(DVertex &u, int& time) {
  time++;
  u.d = time;
  u.state = GRAY;
  // for each vertex adjacent to u, drill down
  for (auto &v : adjancency_list.at(u.name)) {
    // just found a new vertex
    if (v.state == WHITE) {
      v.pred = u.name;
      dfsVisit(v, time);
    }
  }
  u.state = BLACK;
  time++;
  u.f = time;
}
} // namespace chapter22