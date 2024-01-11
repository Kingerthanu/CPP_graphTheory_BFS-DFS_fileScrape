#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include <queue>

class Graph
{

  private:
    bool** adjacencyList = nullptr;
    int size; // The size of our n x n matrix

    void dfs(int& vertex, bool*& walkedVertexes); // Recursive function of DFS
    void getRowstoCols(const std::string connection, int& r, int& c); // Extract rows and columns from text

  public:
    void load(char* filename);  // Construct given adjacency List

    void display(); // Display our adjacency list
    void displayDFS(int vertex);  // Display DFS (pings recursive definition)
    void displayBFS(int vertex);  // Display BFS (handled itself)

    Graph();  // Can have empty constructor as will be null until load is called
    ~Graph(); // Unallocate adjacencyList

};


#endif