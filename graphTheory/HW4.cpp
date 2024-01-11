#include "Graph.h"

int main(int argc, char* argv[])
{

  // Matrix used for traversal
  Graph matrix;

  // Given file to use
  std::string filePath;

  // The origin (infer 0 if not given as arg)
  int origin = 0;

  // Grab data passed in for traversal (else ask for file and its origin)
  switch(argc){

    case 1: // Case given no file, ask for file and origin to use.
      std::cout << "\nWhat file do you want to use and what origin? ";
      std::cin >> filePath >> origin;
      break;
    case 2: // Case given only file, no origin.
      filePath = (argv[1]);
      break;
    case 3: // Case given both file and origin.
      filePath = (argv[1]);
      origin = std::stoi(argv[2]);
      break;

  };

  // Load Doc
  matrix.load(&filePath[0]);

  // Display Adjacency Matrix
  matrix.display();
  std::cout << '\n';
  
  // Display DFS
  matrix.displayDFS(origin);
  std::cout << '\n';

  // Display BFS
  matrix.displayBFS(origin);
  std::cout << "\n\n";
  

}