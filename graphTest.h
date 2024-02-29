/*********************
* Name: Carter Atnip
* Programming III: Data structures
* graph test data class header
**********************/

#ifndef GRAPHTEST_H
#define GRAPHTEST_H

#define GRAPH_TEST_DATA_BASE 20
#define TEST_DATA_OFFSET 1
#define MAXID 100
#define OVERTEST 10
#define GRAPHRANDSELECT 13

#include "iostream"
#include "string"
#include "random"
#include "graph.h"

using std::string;
using std::cout;
using std::endl;

class GraphTest {
public:
    //default constructor
    GraphTest();

    //primary constructor
    explicit GraphTest(int);

    void displayTestData();

    void addVertexTest(Graph&, bool = false);

    void addEdgeTest(Graph&, bool = false);

    void removeEdgeTest(Graph&, bool = false);

    void removeVertexTest(Graph&, bool = false);

    void clearTest(Graph&, bool = false);

    void isEmptyTest(Graph&, bool = false);

    void edgeCountTest(Graph&, bool = false);

    void vertexCountTest(Graph&, bool = false);

    void containsTest(Graph&, bool = false);

    void getVertexTest(Graph&, bool = false);

    void depthFirstSearchTest(Graph&, bool = false);

    void breadthFirstSearchTest(Graph&, bool = false);

    void edgeExistsTest(Graph&, bool = false);

    void randomTesting(Graph&, bool = false);

    //destructor
    ~GraphTest();

private:
    void createConnectedGraph(Graph&);

    void fillIntArray();

    void fillStrArray();

    int *int_array;

    string *str_array;

    int size;
};


#endif //GRAPHTEST_H
