#include <map>
#include <set>
#include <utility>

namespace chapter24 {
    
    // alias some types to make things more readable
    typedef int Vertex;
    typedef std::pair<int, int> Edge;

    class WeightedGraph {
        private:
            std::set<Vertex> vertices_;
            std::map<Edge, int> weights_;
            std::map<Vertex, std::set<Vertex>> adjacency_list_;

            void relax(Vertex, Vertex, std::map<Vertex, int> &);

        public:
            WeightedGraph() = default;
            WeightedGraph(std::set<Vertex>, std::map<Edge,int>);

            // Dijkstra's algorithm to return the length of the 
            // singe source shortest path
            std::map<Vertex, int> Dijkstra(Vertex);
    };
} //namespace chapter24
