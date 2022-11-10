#include "Graph.hpp"

namespace chapter22 {

Graph::Graph(std::vector<Vertex> vertices,
             std::unordered_map<int, std::vector<Vertex>> adj_list) {
  this->vertices = vertices;
  adjacency_list = adj_list;
}

void Graph::breadthFirstSearch(Vertex &s) {
  // our vertices are set to be undiscovered and have d = MAX_INT
  std::queue<Vertex> Q;
  // push our starting vertex onto the queue
  Q.push(s);
  s.color = GRAY;
  s.d = 0;

  // now we do BFS
  while (!Q.empty()) {
    Vertex u = Q.front();
    Q.pop();

    for (Vertex v : adjacency_list.at(u.id)) {
      // check if we've newly discovered v
      if (v.color == WHITE) {
        v.d = u.d+1;
        v.color = GRAY;
        v.pred = u.id;
        Q.push(v);
      }
    }
    // we're done with u, so mark it completed
    u.color = BLACK;
  }
}
} // namespace chapter22