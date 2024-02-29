/*********************
* Name: Carter Atnip
* Programming III: Data structures
* graph test logic
**********************/

#include "graphTest.h"

// default constructor
GraphTest::GraphTest() {
    int_array = new int[GRAPH_TEST_DATA_BASE];
    str_array = new string [GRAPH_TEST_DATA_BASE];
    size = GRAPH_TEST_DATA_BASE;

    fillIntArray();
    fillStrArray();
}

//constructor
GraphTest::GraphTest(int id) {
    if (id < TEST_DATA_OFFSET) {id = GRAPH_TEST_DATA_BASE;}

    int_array = new int[id];
    str_array = new string [id];
    size = id;

    fillIntArray();
    fillStrArray();
}

/*********************
* Name: fillIntArray
* Parameters: None
* Returns: None
* fills int array and forces the second to last int to be a duplicate and the last to be -1
**********************/
void GraphTest::fillIntArray() {
    int resize = size - 2;

    for (int i = 0; i < resize; ++i) {int_array[i] = rand() % MAXID + 1;}

    int_array[resize] = int_array[0];
    int_array[resize + 1] = -1;
}

/*********************
* Name: fillStrArray
* Parameters: None
* Returns: None
* fills string array and forces the last string to be empty
**********************/
void GraphTest::fillStrArray() {
    int resize = size - 1;

    int rnum;

    for (int i = 0; i < resize; ++i) {
        rnum = rand() % GRAPH_TEST_DATA_BASE + 1;

        char *buffer = new char[rnum+1];

        int j = 0;
        for(; j < rnum; j++){
            buffer[j] = (rand() % ('Z' - 'A' + 1)) + 'A';
        }
        buffer[j] = '\0';

        str_array[i] = buffer;

        delete[] buffer;
    }

    str_array[resize] = "";
}

/*********************
* Name: displayTestData
* Parameters: None
* Returns: None
* displays test data to console
**********************/
void GraphTest::displayTestData() {
    cout << "Displaying Test Data for AdjacencyList class..." << endl;

    for (int i = 0; i < size; ++i) {
        cout << i << ": " << int_array[i] << " : " << str_array[i] << endl;
    }
    cout << endl;
}

/*********************
* Name: addVertexTests
* Parameters: None
* Returns: None
* Adds test data to graph
**********************/
void GraphTest::addVertexTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Add Vertex test..." << endl;

        for (int i = 0; i < size; ++i) {
            if (graph.addVertex(int_array[i], str_array[i])) {cout << "Successfully added " << int_array[i] << " : " << str_array[i] << endl;}

            else {cout << "Failed to add " << int_array[i] << " : " << str_array[i] << endl;}
        }
        cout << endl;

        cout << "Successfully completed add vertex test" << endl << endl;
    }

    else {for (int i = 0; i < size; ++i) {graph.addVertex(int_array[i], str_array[i]);}}
}

/*********************
* Name: addEdgeTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* stress tests add edge method
**********************/
void GraphTest::addEdgeTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Add Edge test..." << endl;
        cout << "Testing with valid data and duplicates..." << endl;

        int j = size - 3;

        for (int i = 0; i < size && j!=0; ++i, --j) {
            if (graph.addEdge(int_array[i], int_array[j])) {
                cout << "Successfully added edge between " << int_array[i] << " and " << int_array[j] << endl;
            }

            else {cout << "Failed to add edge between " << int_array[i] << " and " << int_array[j] << endl;}
        }

        cout << endl;

        cout << "Testing duplicate data" << endl;

        j = size - 3;

        for (int i = 0; i < size && j!=0; ++i, --j) {
            if (graph.addEdge(int_array[i], int_array[j])) {
                cout << "Successfully added edge between " << int_array[i] << " and " << int_array[j] << endl;
            }

            else {cout << "Failed to add edge between " << int_array[i] << " and " << int_array[j] << endl;}
        }

        cout << endl;

        cout << "Testing Random Data and invalid data" << endl;
        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand() % 100;
            int rand2 = rand() % 100;

            if (graph.addEdge(rand1, rand2)) {
                cout << "Successfully added edge between " << rand1<< " and " << rand2 << endl;
            }

            else {cout << "Failed to add edge between " << rand1 << " and " << rand2 << endl;}
        }

        cout << endl;
        cout << "Add edge test complete" << endl << endl;

    } else {
        int j = size - 3;

        for (int i = 0; i < size; ++i, --j) {graph.addEdge(int_array[i], int_array[j]);}

        j = size - 3;

        for (int i = 0; i < size; ++i, --j) {graph.addEdge(int_array[i], int_array[j]);}

        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand();
            int rand2 = rand();
            graph.addEdge(rand1, rand2);

        }
    }
}

/*********************
* Name: removeEdgeTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests remove edge method
**********************/
void GraphTest::removeEdgeTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Remove Edge test..." << endl;
        cout << "Testing with valid data and duplicates..." << endl;

        int j = size - 3;

        for (int i = 0; i < size && j!=0; ++i, --j) {
            if (graph.removeEdge(int_array[i], int_array[j])) {
                cout << "Successfully deleted edge between " << int_array[i] << " and " << int_array[j] << endl;
            }

            else {cout << "Edge does not exist between " << int_array[i] << " and " << int_array[j] << endl;}
        }

        cout << endl;

        cout << "Testing duplicate data" << endl;

        j = size - 3;

        for (int i = 0; i < size && j!=0; ++i, --j) {
            if (graph.removeEdge(int_array[i], int_array[j])) {
                cout << "Successfully deleted edge between " << int_array[i] << " and " << int_array[j] << endl;
            }

            else {cout << "Edge does not exist between " << int_array[i] << " and " << int_array[j] << endl;}
        }

        cout << endl;

        cout << "Testing Random invalid data" << endl;
        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand() % 100;
            int rand2 = rand() % 100;

            if (graph.removeEdge(rand1, rand2)) {
                cout << "Successfully removed edge between " << rand1<< " and " << rand2 << endl;
            }

            else {cout << "Edge does not exist between " << rand1 << " and " << rand2 << endl;}
        }

        cout << endl;
        cout << "Remove edge test complete" << endl;

        cout << "Refilling for next test" << endl << endl;

        addEdgeTest(graph);
    } else {
        int j = size - 3;

        for (int i = 0; i < size; ++i, --j) {graph.removeEdge(int_array[i], int_array[j]);}

        j = size - 3;

        for (int i = 0; i < size; ++i, --j) {graph.removeEdge(int_array[i], int_array[j]);}

        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand();
            int rand2 = rand();
            graph.removeEdge(rand1, rand2);
        }
        addEdgeTest(graph);
    }
}

/*********************
* Name: removeVertexTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests remove vertex method
**********************/
void GraphTest::removeVertexTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Remove Vertex test..." << endl;

        for (int i = 0; i < size; ++i) {
            if (graph.removeVertex(int_array[i])) {cout << "Successfully removed " << int_array[i] << " : " << str_array[i] << endl;}

            else {cout << "ID does not exist " << int_array[i] << endl;}
        }
        cout << endl;

        cout << "Beginning random test" << endl;

        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand_int = rand();

            if (graph.removeVertex(rand_int)) {cout << "Successfully removed " << rand_int << endl;}

            else {cout << "ID does not exist " << rand_int << endl;}
        }

        cout << "Finished Remove Vertex Test" << endl;

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);
    }

    else {
        for (int i = 0; i < size; ++i) {graph.removeVertex(int_array[i]);}

        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand_int = rand();
            graph.removeVertex(rand_int);
        }

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: clearTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests remove edge method
**********************/
void GraphTest::clearTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Clear Test..." << endl;

        cout << "Testing clear on graph with data" << endl;

        if (graph.clear()) {cout << "Successfully cleared graph" << endl;}
        else {cout << "Failed to clear graph" << endl;}

        cout << "Testing clear on graph without data" << endl;

        if (graph.clear()) {cout << "Successfully cleared graph" << endl;}
        else {cout << "Failed to clear graph" << endl;}

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        graph.clear();

        graph.clear();

        addVertexTest(graph);
        addEdgeTest(graph);

    }
}

/*********************
* Name: isEmptyTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests isEmpty method
**********************/
void GraphTest::isEmptyTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Empty test..." << endl;

        cout << "Testing Empty on graph with data" << endl;

        if (graph.isEmpty()) {cout << "The graph is empty" << endl;}
        else {cout << "The graph has data" << endl << endl;}

        cout << "Testing Empty on graph without data" << endl;

        graph.clear();

        if (graph.isEmpty()) {cout << "The graph is empty" << endl;}
        else {cout << "The graph has data" << endl;}

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        graph.isEmpty();

        graph.clear();

        graph.isEmpty();

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: edgeCountTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests edgeCount method
**********************/
void GraphTest::edgeCountTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Edge Count test..." << endl;

        cout << "Testing on graph with edges" << endl;
        cout << "There are " << graph.edgeCount() << " edges in the graph" << endl << endl;

        graph.clear();

        cout << "Testing on graph without edges" << endl;
        cout << "There are " << graph.edgeCount() << " edges in the graph" << endl << endl;

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        graph.edgeCount();

        graph.clear();

        graph.edgeCount();

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}


/*********************
* Name: edgeCountTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests edgeCount method
**********************/
void GraphTest::vertexCountTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Vertex Count test..." << endl;

        cout << "Testing on graph with vertices" << endl;
        cout << "There are " << graph.vertexCount() << " vertices in the graph" << endl << endl;

        graph.clear();

        cout << "Testing on graph without vertices" << endl;
        cout << "There are " << graph.vertexCount() << " vertices in the graph" << endl << endl;

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        graph.vertexCount();

        graph.clear();

        graph.vertexCount();

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: containsTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests contains method
**********************/
void GraphTest::containsTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Contains test..." << endl;
        cout << "Testing on valid and negative IDs" << endl;

        for (int i = 0; i < size; ++i) {
            if (graph.contains(int_array[i])) {cout << int_array[i] << " : Exists" << endl;}
            else {cout << int_array << " : Does not exist" << endl;}
        }

        cout << endl;

        cout << "Testing random data" << endl;

        int randint;

        for (int i = 0; i < size * OVERTEST; ++i) {
            randint = rand() % MAXID;

            if (graph.contains(randint)) {cout << randint<< " : Exists" << endl;}
            else {cout << randint << " : Does not exist" << endl;}
        }

        cout << endl;

        cout << "Testing on empty graph" << endl;

        graph.clear();

        if (graph.contains(randint)) {cout << randint<< " : Exists" << endl;}
        else {cout << randint << " : Does not exist" << endl;}

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        for (int i = 0; i < size; ++i) {graph.contains(int_array[i]);}

        int randint;

        for (int i = 0; i < size * OVERTEST; ++i) {
            randint = rand() % MAXID;
            graph.contains(randint);
        }

        graph.clear();

        graph.contains(randint);

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: getVertexTest
* Parameters: graph (pbr), verbose (bool default false)
* Returns: None
* tests getVertex method
**********************/
void GraphTest::getVertexTest(Graph &graph, bool verbose) {
    Data data;

    if (verbose) {
        cout << "Beginning Get Vertex test..." << endl;
        cout << "Testing on valid and negative IDs" << endl;

        for (int i = 0; i < size; ++i) {
            if (graph.getVertex(int_array[i],data)) {cout << "Found "<< data.id << " : " << data.data << endl;}
            else {cout << "Unable to find " << int_array[i] << " "<< data.id << " : " << data.data << endl;}
        }

        cout << endl;

        cout << "Testing random data" << endl;

        int randint;

        for (int i = 0; i < size * OVERTEST; ++i) {
            randint = rand() % MAXID;

            if (graph.getVertex(randint,data)) {cout << "Found "<< data.id << " : " << data.data << endl;}
            else {cout << "Unable to find " << randint << " "<< data.id << " : " << data.data << endl;}
        }

        cout << endl;

        cout << "Testing on empty graph" << endl;

        graph.clear();

        if (graph.getVertex(randint,data)) {cout << "Found "<< data.id << " : " << data.data << endl;}
        else {cout << "Unable to find " << randint << " "<< data.id << " : " << data.data << endl;}

        cout << "Refilling for next test" << endl << endl;

        addVertexTest(graph);
        addEdgeTest(graph);

    } else {
        for (int i = 0; i < size; ++i) {graph.getVertex(int_array[i], data);}

        int randint;

        for (int i = 0; i < size * OVERTEST; ++i) {
            randint = rand() % MAXID;
            graph.getVertex(randint, data);
        }

        graph.clear();

        graph.getVertex(randint, data);

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: createConnectedGraph
* Parameters: graph (pbr)
* Returns: None
* creates a connected graph
**********************/
void GraphTest::createConnectedGraph(Graph &graph) {
    graph.clear();

    addVertexTest(graph);

    for (int i = 0; i < size; ++i) {for (int j = 1; j < size; ++j) {graph.addEdge(int_array[i],int_array[j]);}}
}

/*********************
* Name: depthFirstSearchTest
* Parameters: graph (pbr), verbose (bool)
* Returns: None
* tests the depthFirstSearch method
**********************/
void GraphTest::depthFirstSearchTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning DFS test..." << endl;

        cout << "Testing on disconnected graph" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Testing at starting vertex: " << int_array[i] << endl;

            if (graph.depthFirstSearch(int_array[i])) {}
            else {cout << "Vertex does not exist" << endl;}
        }

        cout << "Testing on connected graph" << endl;
        createConnectedGraph(graph);

        for (int i = 0; i < size; ++i) {
            cout << "Testing at starting vertex: " << int_array[i] << endl;

            if (graph.depthFirstSearch(int_array[i])) {}
            else {cout << "Vertex does not exist" << endl;}
        }

        cout << "Testing on empty graph" << endl;
        graph.clear();
        if (graph.depthFirstSearch(int_array[1])) {}
        else {cout << "Vertex does not exist" << endl << endl;}

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: breadthFirstSearchTest
* Parameters: graph (pbr), verbose (bool)
* Returns: None
* tests the breadthFirstSearch method
**********************/
void GraphTest::breadthFirstSearchTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning BFS test..." << endl;

        cout << "Testing on disconnected graph" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Testing at starting vertex: " << int_array[i] << endl;

            if (graph.breadthFirstSearch(int_array[i])) {}
            else {cout << "Vertex does not exist" << endl;}
        }

        cout << "Testing on connected graph" << endl;
        createConnectedGraph(graph);

        for (int i = 0; i < size; ++i) {
            cout << "Testing at starting vertex: " << int_array[i] << endl;

            if (graph.breadthFirstSearch(int_array[i])) {}
            else {cout << "Vertex does not exist" << endl;}
        }

        cout << "Testing on empty graph" << endl;
        graph.clear();
        if (graph.breadthFirstSearch(int_array[1])) {}
        else {cout << "Vertex does not exist" << endl << endl;}

        addVertexTest(graph);
        addEdgeTest(graph);
    }
}

/*********************
* Name: edgeExistsTest
* Parameters: graph (pbr), verbose (bool)
* Returns: None
* tests the edgeExists method
**********************/
void GraphTest::edgeExistsTest(Graph &graph, bool verbose) {
    if (verbose) {
        cout << "Beginning Edge Exists test..." << endl;

        cout << "Testing valid data" << endl;

        int j = size - 3;

        for (int i = 0; i < size && j!=0; ++i, --j) {
            if (graph.edgeExists(int_array[i], int_array[j])) {cout << "Edge exists between " << int_array[i] << " and " << int_array[j] << endl;}

            else {cout << "Edge does not exist between " << int_array[i] << " and " << int_array[j] << endl;}
        }

        j = size -3;

        cout << "Testing Random Data and invalid data" << endl << endl;
        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand() % 100;
            int rand2 = rand() % 100;

            if (graph.edgeExists(rand1, rand2)){cout << "Edge exists between " << rand1<< " and " << rand2 << endl;}
            else {cout << "Edge does not exists between " << rand1 << " and " << rand2 << endl;}
        }
    } else {
        int j = size - 3;

        for (int i = 0; i < size; ++i, --j) {graph.edgeExists(int_array[i], int_array[j]);}

        j = size - 3;

        for (int i = 0; i < size * OVERTEST; ++i) {
            int rand1 = rand();
            int rand2 = rand();
            graph.edgeExists(rand1, rand2);

        }
    }
}

void GraphTest::randomTesting(Graph &graph, bool verbose) {
    if (verbose) {cout << "Beginning Random Testing" << endl;}

    int loops = size * OVERTEST;

    for (int i = 0; i < loops; ++i) {
        int selection = rand() % GRAPHRANDSELECT;

        switch (selection) {
            case 0:
                addVertexTest(graph, verbose);
                break;

            case 1:
                addEdgeTest(graph, verbose);
                break;

            case 2:
                removeEdgeTest(graph, verbose);
                break;

            case 3:
                removeVertexTest(graph, verbose);
                break;

            case 4:
                clearTest(graph, verbose);
                break;

            case 5:
                isEmptyTest(graph, verbose);
                break;

            case 6:
                edgeCountTest(graph, verbose);
                break;

            case 7:
                vertexCountTest(graph, verbose);
                break;

            case 8:
                containsTest(graph, verbose);
                break;

            case 9:
                getVertexTest(graph, verbose);
                break;

            case 10:
                depthFirstSearchTest(graph, verbose);
                break;

            case 11:
                breadthFirstSearchTest(graph, verbose);
                break;

            case 12:
                edgeExistsTest(graph, verbose);
                break;
        }
    }
}



//destructor
GraphTest::~GraphTest() {
    delete[] int_array;
    delete[] str_array;
}



