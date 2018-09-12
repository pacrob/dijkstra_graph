#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

class Dijkstra {
 
public:
      
  Dijkstra();
  Dijkstra(int num_nodes);
  void print_graph();
  int initialize_graph(double density, double distance_range);
  double get_avg_shortest_path();
  double get_shortest_path(int node);

private:
  int size_;
  std::vector<std::vector<double>> graph_;

};
  

#endif
