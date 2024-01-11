#include "Graph.h"

Graph::Graph()
{

  // No need for anything in constructor.

}

Graph::~Graph()
{

  for(int i = 0; i < this->size; i++){

    delete[] this->adjacencyList[i];

  }

  delete[] this->adjacencyList;

}

// Precondition: Expects perfect format (no extra trailing spaces) 
void Graph::getRowstoCols(const std::string connection, int& r, int& c)
{

  // Will be where each piece is stored while getting its parts
  std::string handler = "";

  // Will Flip from left to right side (row -> col)
  bool flag = true;

  // For each char in our given relation
  for(const char& each : connection){

    // If not middle space 
    if(each != ' '){

      if(flag){   // Get row

        handler += each;
        
      }
      else{       // Get column

        handler += each;

      }

    }
    else{   // If hit empty space, then start placing in column

      r = std::stoi(handler);      
      handler = "";
      flag = false;

    }

  }

  // Now add to column val
  c = std::stoi(handler); 


}

void Graph::load(char* filename)
{
  
  // Grab the file
  std::ifstream graphFile(filename);

  // If a invalid file
  if(!graphFile.is_open()){

    std::cout << "File is Not Accessible\n";
    return;

  }

  // We know first line will be dimension (expecting proper format)
  std::string currentLine;
  std::getline(graphFile, currentLine);

  int row, col;
  this->size = std::stoi(currentLine);
  this->adjacencyList = new bool*[this->size];

  // Allocate spots for data
  for(int i = std::stoi(currentLine)-1; i != -1; i--){

    this->adjacencyList[i] = new bool[this->size]{0};

  }


  // Grab each relation and make a two way connection from txt doc
  while(std::getline(graphFile, currentLine)){

    // Grab current lines data and place into row, col variables
    this->getRowstoCols(currentLine, row, col);

    // Two way connection so flip
    this->adjacencyList[row][col] = 1;
    this->adjacencyList[col][row] = 1;

    

  }

}

void Graph::display()
{

  // Set top prompt
  std::cout << "\nAdjacency Matrix:\n";

  // Go through each row and column and print bool value of associated position
  for(int i = 0; i < this->size; i++){

    for(int d = 0; d < this->size; d++){

      std::cout << this->adjacencyList[i][d] << ' ';

    }

    // Padding
    std::cout << '\n';

  }

}

void Graph::dfs(int& vertex, bool*& walkedVertexes)
{

  // Print currently stepped on vertex
  std::cout << vertex << ' ';

  // Scan through each possible connection in this given row (or given vertex)
  for(int i = 0; i < this->size; i++){

    // If we are connected with this vertex and haven't already checked it then check
    if(this->adjacencyList[vertex][i] && !walkedVertexes[i]){

      walkedVertexes[i] = true;      
      dfs(i, walkedVertexes);

    }

  }

}

void Graph::displayDFS(int vertex)
{

  // Create a container for walked vertexes
  bool* steppedOn = new bool[this->size]{0};
  steppedOn[vertex] = true;               // Set origin as stepped on
 
  // Print header
  std::cout << "Displaying Depth First (DFS) Traversal at origin " << vertex << ": \n";

  // Now print the others...
  dfs(vertex, steppedOn);

  // Clear up dynamic helper variable
  delete[] steppedOn;

}

void Graph::displayBFS(int vertex)
{
  
  std::queue<int> vertexes;
  bool* walkedVertexes = new bool[this->size]{0};
  walkedVertexes[vertex] = true;

  vertexes.push(vertex);

  std::cout << "\nDisplaying Breadth First Traversal (BFT) at origin " << vertex << ": \n";

  while(!vertexes.empty()){
    
    vertex = vertexes.front();
    vertexes.pop();

    std::cout << vertex << ' ';

    for(int i = 0; i < this->size; i++){

      if(this->adjacencyList[vertex][i] && !walkedVertexes[i]){

        vertexes.push(i);
        walkedVertexes[i] = true;


      }

    }

  }

  delete[] walkedVertexes;
  

}