/*********************
* Name: Carter Atnip
* Programming III: Data structures
* main file for Graph data structure
**********************/

#include "main.h"

int main() {
    int seed = time(NULL);
    srand(seed);

    cout << "Seed: " << seed << endl << endl;

    AdjacencyListTestData ListTest(TESTSIZE);

    AdjacencyList list;

    ListTest.fullTest(list);

    GraphTest graphTestdata(8);

    Graph graph;

    graphTestdata.displayTestData();

    graphTestdata.addVertexTest(graph, true);

    graphTestdata.addEdgeTest(graph, true);

    graphTestdata.removeEdgeTest(graph, true);

    graphTestdata.removeVertexTest(graph, true);

    graphTestdata.clearTest(graph, true);

    graphTestdata.isEmptyTest(graph, true);

    graphTestdata.edgeCountTest(graph, true);

    graphTestdata.vertexCountTest(graph, true);

    graphTestdata.containsTest(graph, true);

    graphTestdata.getVertexTest(graph, true);

    graphTestdata.depthFirstSearchTest(graph, true);

    graphTestdata.breadthFirstSearchTest(graph, true);

    graphTestdata.edgeExistsTest(graph, true);

    graphTestdata.randomTesting(graph, true);

    return 0;
}