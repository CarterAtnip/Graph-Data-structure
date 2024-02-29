/*********************
* Name: Carter Atnip
* Programming III: Data structures
* Header file for graph class
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "string"
#include "iostream"
#include "vector"
#include "adjacencyList.h"
#include "data.h"
#include "queue"

using std::string;
using std::cout;
using std::endl;

#define SETCOUNT 0

class Graph {
public:
    //constructor
    Graph();

    bool addVertex(int, string&);

    bool addEdge(int, int);

    bool removeEdge(int, int);

    bool removeVertex(int);

    bool clear();

    bool isEmpty();

    int edgeCount();

    int vertexCount();

    bool contains(int);

    bool getVertex(int, Data&);

    bool depthFirstSearch(int);

    bool breadthFirstSearch(int);

    bool edgeExists(int, int);

    //destructor
    ~Graph();

private:
    void depthFirstSearch(int, std::vector<bool>&);

    bool getVertexIndexAndData(int, int &, Data&);

    std::vector<AdjacencyList*> graph;

    int vertex_count;

    int edge_count;
};


#endif //GRAPH_H