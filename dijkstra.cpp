#include "dijkstra.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

// prints graph out to console
void Dijkstra::print_graph() {
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      std::cout << graph_[i][j] << " ";
    }
    std::cout << "\n";
  }
}

// fill graph - for each node, if rand is less than density, fill with rand from 1.0 to distance_range
int Dijkstra::initialize_graph(double density, double distance_range) {

  std::srand(std::time(0)); // seed for rand()

  for (int i = 0; i < size_; i++) {
    for (int j = i; j < size_; j++) {
      if (i == j){
        graph_[i][j] = 0;
      }
      else {
        double density_roll = static_cast<double>(rand() % 9 + 1) / 10;
        if (density_roll <= density){
          double edge_weight = static_cast<double>(rand() % static_cast<int>(distance_range * 10)) / 10;
          graph_[i][j] = edge_weight;
          graph_[j][i] = edge_weight;
        }
      }
    }
  }
  return 0;
}

double Dijkstra::get_avg_shortest_path() {
  return 0.0;
}

double Dijkstra::get_shortest_path(int node){
  return 0.0;
}




