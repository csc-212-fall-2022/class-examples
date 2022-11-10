#ifndef CLASS_EXAMPLES_GRAPH_HPP
#define CLASS_EXAMPLES_GRAPH_HPP

#include <unordered_map>
#include <vector>
#include <climits>
#include "bits/stdc++.h"

namespace chapter22 {

enum Color { WHITE, GRAY, BLACK };

struct Vertex {
  int id; // name of the vertex
  Color color;
  int d; // int value from BFS
  int pred; // predecessor vertex (vertex from which we discover this one)
  // some other stuff if we wanted to decorate our vertices

  Vertex(int vertexId) {
    id = vertexId;
    color = WHITE; // undiscovered
    d = INT_MAX;
    pred = INT_MIN;
  }
};

// a graph with an adjacency list representation
class Graph {
private:
  // Having a separate vertices vector is silly, but I'm not messing about
  // figuring out how to override std::hash for Vertex
  std::vector<Vertex> vertices;
  std::unordered_map<int, std::vector<Vertex>> adjacency_list;

public:
  Graph(std::vector<Vertex>, std::unordered_map<int, std::vector<Vertex>>);
  void breadthFirstSearch(Vertex &);
};

}

#endif // CLASS_EXAMPLES_GRAPH_HPP
