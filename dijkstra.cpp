#include "dijkstra.hpp"
#include <iostream>
#include <vector>

// default constructor
Dijkstra::Dijkstra() {
  size_ = 0;
}

// creates a 2d vector of specified size filled with 0s
Dijkstra::Dijkstra(int num_nodes) {
  size_ = num_nodes;

  for (int i = 0; i < num_nodes; i++) {
    std::vector<double> new_row;
    graph_.push_back(new_row);
    for (int j = 0; j < num_nodes; j++) {
      graph_[i].push_back(0);
    }
  }


}

void Dijkstra::print_graph() {
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      std::cout << graph_[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int Dijkstra::initialize_graph(double density, double distance_range) {
  return 0;
}

double Dijkstra::get_avg_shortest_path() {
  return 0.0;
}

double Dijkstra::get_shortest_path(int node){
  return 0.0;
}




