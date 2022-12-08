#include "Graph.hpp"
#include <climits>

namespace chapter24 {

// put this prototype here
Vertex extract_min(std::map<Vertex, int> weights);

WeightedGraph::WeightedGraph(std::set<Vertex> vertices,
                             std::map<Edge, int> weights) {
  vertices_ = vertices;
  weights_ = weights;
}

auto WeightedGraph::Dijkstra(Vertex source) -> std::map<Vertex, int> {
  // first initialize all v.d = inf (and then s.d=0)
  std::map<Vertex, int> shortest_path_weights; // hold our v.d
  for (const Vertex &v : vertices_) {
    shortest_path_weights.insert(v, INT_MAX);
  }
  // update source.d
  shortest_path_weights.at(source) = 0;

  // make the set S of completed vertices
  std::set<Vertex> visited;

  // let's be a bit lazy and just use shortest_path_weights as our queue
  // It turns out that this is a reasonable choice when the graph is "dense".
  // There are a number of tradeoffs/optimizations to be made in implementing
  // Dijkstra's algorithm.

  // reusing shortest_path_weights this way means we need to change our
  // termination condition a little
  while (visited.size() <
         vertices_.size()) { // until we've visited every vertex
    auto u = extract_min(shortest_path_weights);
    visited.insert(u);
    for (const Vertex &v : adjacency_list_.at(u)) {
      relax(u, v, shortest_path_weights);
    }
  }
  return shortest_path_weights;
}

void WeightedGraph::relax(Vertex u, Vertex v, // NOLINT
                          std::map<Vertex, int> &vertex_weights) {
  int vd = vertex_weights.at(v);
  int ud = vertex_weights.at(u);
  Edge e = {u, v}; // three cheers for list initializer!
  if (weights_.count(e)) { // if the edge really exists
    int edge_weight = weights_.at(e);
    if (ud < INT_MAX && vd > ud + edge_weight) { // check that u_d is finite so 
        // we
        // don't
        // roll
        // over
        vd = ud + edge_weight;
        vertex_weights.at(v) = vd;
    }
  }
}

// find the vertex with the smallest weight
// the name
// extract_min comes
// from the priority queue method name--here we're not actually removing anything
Vertex extract_min(std::map<Vertex, int> weights) {
  int min_weight = INT_MAX;
  Vertex min;
  for (const auto &[v, w] : weights) {
    if (w < min_weight) {
      min_weight = w;
      min = v;
    }
  }
  return min;
}

} // namespace chapter24
