/*********************
* Name: Carter Atnip
* Programming III: Data structures
* header for adjacency list class
**********************/

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "iostream"
#include "data.h"
#include "string"
#include "vector"

#define DEFAULTCOUNT 0

using std::string;
using std::cout;
using std::endl;

class AdjacencyList {
public:
    //constructor
    AdjacencyList();

    bool addNode(int, string*);

    bool deleteNode(int);

    bool getHead(Data*);

    bool getNode(int, Data*);

    bool getIdsAsVector (std::vector<int>&);

    void printList(bool = false);

    int getCount();

    bool clearList();

    bool exists(int);

    // destructor
    ~AdjacencyList();

private:
    // inserting node helper methods
    bool insertHead(Node*);

    bool insertTail(Node*, Node*);

    // removing node helper methods

    void removeMiddle(Node*);

    void removeTail(Node*);

    //attributes
    Node *head;

    int count;
};


#endif //ADJACENCYLIST_H
