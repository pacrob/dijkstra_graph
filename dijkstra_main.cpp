#include "dijkstra.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {

  std::srand(std::time(0)); // seed for rand()

  int size;
  double range;
  double density;

  std::cout << "Enter integer graph size\n";
  std::cin >> size;
  std::cout << "Enter double edge length max\n";
  std::cin >> range;
  std::cout << "Enter a density between 0.0 and 1.0, both exclusive\n";
  std::cin >> density;

  Dijkstra d_graph = Dijkstra(size);
  std::cout << "uninitialized graph is:\n";
  d_graph.print_graph();
  d_graph.initialize_graph(density, range);
  std::cout << "initialized graph is:\n";
  d_graph.print_graph();
  std::cout << "Average shortest path is " << d_graph.get_avg_shortest_path() << "\n";

  int testnode = 1;

  while (testnode > 0) {
    std::cout << "Enter a node number to get the shortest path from 1 or 0 to quit\n";
    std::cin >> testnode;
    if (testnode > 0) {
      std::cout << "Shortest path from node 1 to node " << testnode << " is " << d_graph.get_shortest_path(testnode) << "\n";
    }
  }

}


