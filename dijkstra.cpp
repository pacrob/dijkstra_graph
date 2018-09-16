#include "dijkstra.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

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
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      std::cout << graph_[i][j] << " ";
    }
    std::cout << "\n";
  }
}
// prints open and closed vectors out to console
void Dijkstra::print_vectors() {
  int x;
  double y;
  std::cout << "closed is: ";
  for (auto i : closed_){
    x = std::get<0>(i);
    y = std::get<1>(i);
    std::cout << "(" << x << ", " << y << ") ";
  }
  std::cout << "\n";
  std::cout << "open is: ";
  for (auto i : open_){
    x = std::get<0>(i);
    y = std::get<1>(i);
    std::cout << "(" << x << ", " << y << ") ";
  }
  std::cout << "\n";
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

void Dijkstra::append_node_to_open(int node, double value){
  open_.push_back(std::tuple<int, double>(node, value));
}
void Dijkstra::append_node_to_closed(int node, double value){
  closed_.push_back(std::tuple<int, double>(node, value));
}

double Dijkstra::get_avg_shortest_path(){
  // calculate shortst paths to each node, will be in closed_
  calc_shortest_paths();

  // sum shortest paths to reachable nodes, divide by number of nodes and return
  double accum = 0.0;
  int count = 0;

  for ( auto i : closed_){
    accum += std::get<1>(i);
    ++count;
  }
  //std::cout << "reachable node count is " << closed_.size() << "\n";
  return (accum / static_cast<double>(count));
}

void Dijkstra::calc_shortest_paths(){

  // add node 0 to closed with distance 0
  append_node_to_closed(0, 0.0);

  // scan graph[0] for values > 0, add (idx,value) to closed
  for (int i = 0; i < size_; i++){
    if (graph_[0][i] > 0){
      append_node_to_open(i, graph_[0][i]);
    }
  }
  
  // print_vectors();
  // while open is not empty
  while (!open_.empty()){

  // scan open for lowest value L
    int lowest_idx = 0;
    int lowest_node = std::get<0>(open_[0]);
    double lowest_value = std::get<1>(open_[0]);
    
    for (int i = 0; i < open_.size(); i++){
      if (std::get<1>(open_[i]) < lowest_value){
        lowest_idx = i;
        lowest_node = std::get<0>(open_[i]);
        lowest_value = std::get<1>(open_[i]);
      } 
    }

    // std::cout << "lowest node " << lowest_node << " lowest val " << "\n";

    // add L's connections to open as (idx, value + L's value) if they're not in open or closed
    for (int i = 0; i < size_; i++){
      if (graph_[lowest_node][i] > 0){
        if (is_node_in_closed(i) < 0 && is_node_in_open(i) < 0){
          open_.push_back(std::tuple<int, double>(i, (graph_[lowest_node][i] + lowest_value) ));
        }
      }
    }

  // add L to closed if it's not there
    if (is_node_in_closed(lowest_node) < 0){
      append_node_to_closed(lowest_node, lowest_value);
    }
    
  // remove L from open
    open_.erase(open_.begin() + lowest_idx);

    // print_vectors();
  } 
}

// returns the index if in, -1 if not
int Dijkstra::is_node_in_open(int node){
  return is_node_in_vector(open_, node);
}

int Dijkstra::is_node_in_closed(int node){
  return is_node_in_vector(closed_, node);
}

int Dijkstra::is_node_in_vector(const std::vector<std::tuple<int, double>> &vec,
                                int value){
  for (int i = 0; i < vec.size(); i++){
    if (std::get<0>(vec[i]) == value){
      return i;
    }
  }
  return -1;
}
