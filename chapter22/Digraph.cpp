#include "Digraph.hpp"
#include "Graph.hpp"
#include <climits>

namespace chapter22 {
Digraph::Digraph(std::unordered_map<int, DVertex> vertices,
                 std::unordered_map<int, std::vector<DVertex>> adjacency_list) {
  this->vertices = vertices;
  this->adjancency_list = adjacency_list;
}

Digraph Digraph::Transpose() {
  // same vertices -- easy
  std::unordered_map<int, std::vector<DVertex>> adj_transpose;
  for (auto const &[n, adj_vertices] : adjancency_list) {
    for (auto const v : adj_vertices) {
      // need to make an edge v -> n
      if (adj_transpose.count(v.name) == 0) {
        adj_transpose.emplace(v.name, std::vector<DVertex>{vertices.at(n)});
      } else {
        adj_transpose.at(v.name).push_back(vertices.at(n));
      }
    }
  }

  return Digraph(vertices, adj_transpose);
}

void Digraph::depthFirstSearch() {
  std::unordered_map<int, Color> vertex_state;
  for (auto &[n, v]: vertices) {
    vertex_state.emplace(n, WHITE);
  }

  // all vertices are white (undiscovered)
  // predecessor is INT_MIN (i.e. undefined)
  int time = 0;
  for (auto &[n, v] : vertices) { // pick a starting point at random
    // we'll visit as many vertices as we can from that starting point, then we'll just pick another
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
  std::cout << "Processing " << u.name << "at" << time << std::endl;
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
  std::cout<< "Vertex " << u.name << " complete at time " << time << std::endl;
}

void Digraph::depthFirstSearchIter() {
  int time = 0;
  std::stack<DVertex> s;
  // Iterate over the items (k,v) in the map -- be we can give the key and value
  // names (here: n, u) in the loop. -- Destructuring
  for (auto &[n, u] : vertices) { // it->first(); it->second()
    // we need this outer loop to account for multiple (strongly) connected components
    if (u.state == WHITE) {
      s.push(u);
      time++;
      u.state = GRAY;
      u.d = time;
      while (!s.empty()) {
        time++;
        // pop the vertex we're going to work on
        DVertex v = s.top();
        s.pop(); // remove it from the stack
        for (auto &w : adjancency_list.at(v.name)) {
          // now we discover the adjacent vertices if we haven't already
          if (w.state == WHITE) {
            time++;
            w.d = time;
            w.state = GRAY;
            s.push(w);
          }
        }
        time++;
        // now we're done with v
        v.state = BLACK;
        // NOTE: This version doesn't obey the Parenthesis Theorem
        v.f = time;
      }
    }
  }
}

  std::deque<DVertex> Digraph::TopologicalSort() {
    // this assumes that we haven't already called DFS
    std::deque<DVertex> top_sort;
    int time = 0;
    for (auto &[n, v] : vertices) {
      // if we've just discovered v, start working on it
      if (v.state == WHITE) {
        topSortVisit(v, time, top_sort);
      }
    }
    return top_sort;
  }

  void Digraph::topSortVisit(DVertex &u, int &time, std::deque<DVertex> &top_sort) {
    time++;
    u.d = time;
    u.state = GRAY;
    for (auto &v : adjancency_list.at(u.name)) {
      if (v.state == WHITE) {
        topSortVisit(v, time, top_sort);
      }
    }
    // now we're done with u
    time++;
    u.f = time;
    u.state = BLACK;
    top_sort.push_front(u);
  }

  auto Digraph::StronglyConnectedComponents() -> std::set<std::set<DVertex>> {
    // step 1: run DFS to get the side effect of computing the finishing times
    depthFirstSearch();
    // step 2: sort the vertices in descending order of finishing times
    std::vector<DVertex> ordered_vertices;
    for (auto [id, dv] : vertices) {
      ordered_vertices.push_back(dv);
    }
    std::sort(ordered_vertices.begin(), ordered_vertices.end(), 
      // this argument tells us how to compare two DVertex (i.e. by their finishing times)
      [](const DVertex &a, const DVertex &b) {
      // we need to sort in reverse order
      return a.f > b.f;
    });
    std::vector<int> vertex_order;
    for (auto dv : ordered_vertices) {
      vertex_order.push_back(dv.name);
    }
    // step 3: run DFS on the transpose, taking the vertices in the order given above
    auto GT = Transpose();
    
    return GT.dfsWithOrder(vertex_order);
  }

  auto Digraph::dfsWithOrder(std::vector<int> vertex_order) -> std::set<std::set<DVertex>> {
    // let's be careful and make sure all vertices are white when we start
    for (int id : vertex_order) {
      DVertex v = vertices.at(id);
      v.state = WHITE;
      v.d = INT_MAX; // we aren't going to care about the times, but for the sake of neatness
      v.f = INT_MAX;
    }
    std::set<std::set<DVertex>> strongly_connected_components;
    for (int id : vertex_order) { // we're visiting the vertices in a specific order this time
      auto v = vertices.at(id);
      if (v.state == WHITE) {
        std::set<DVertex> scc; // make a set to hold the component we're about to build
        dfsComponentVisit(v, scc);
        strongly_connected_components.insert(scc);
      }
    }
    return strongly_connected_components;
  }
  
  void Digraph::dfsComponentVisit(DVertex u, std::set<DVertex> &component) {
    component.insert(u); // insert now or at the end
    u.state = GRAY;
    for (auto v : adjancency_list.at(u.name)) {
      if (v.state == WHITE) {
        dfsComponentVisit(v, component);
      }
    }
    u.state = BLACK;
  }

  } // namespace chapter22