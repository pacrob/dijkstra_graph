#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

class Dijkstra {
 
public:
      
  Dijkstra();
  Dijkstra(int num_nodes);
  void print_graph();
  void print_vectors();
  int initialize_graph(double density, double distance_range);
  void append_node_to_open(int node, double value);
  void append_node_to_closed(int node, double value);
  double get_avg_shortest_path();
  int is_node_in_open(int node);
  int is_node_in_closed(int node);


private:
  int size_;
  void append_node_to_vector(const std::vector<std::tuple<int, double>> &vec, 
                             double value);
  int is_node_in_vector(const std::vector<std::tuple<int, double>> &vec, 
                             int value);
  std::vector<std::vector<double>> graph_;
  std::vector<std::tuple<int, double>> open_;
  std::vector<std::tuple<int, double>> closed_;
};
  

#endif
