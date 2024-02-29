/*********************
* Name: Carter Atnip
* Programming III: Data structures
* logic for graph class
**********************/

#include "graph.h"

//constructor
Graph::Graph() {
    vertex_count = SETCOUNT;
    edge_count = SETCOUNT;
}

/*********************
* Name: addVertex
* Parameters: id (int) data (string pbr)
* Returns: bool
* adds vertex to graph
**********************/
bool Graph::addVertex(int id, string &data) {
    bool success = false;

    if (id > -1 && !data.empty()) {
        Data vertex {-1, ""};

        for (int i = 0; i < vertex_count && id != vertex.id; ++i) {graph[i]->getHead(&vertex);}

        if (vertex.id != id) {
            AdjacencyList *new_list = new AdjacencyList;
            new_list->addNode(id, &data);

            graph.push_back(new_list);

            success = true;
            vertex_count += 1;
        }
    }
    return success;
}

/*********************
* Name: addEdge
* Parameters: vertex1 (int) vertex2 (int)
* Returns: bool
* adds edge to graph
**********************/
bool Graph::addEdge(int vertex1, int vertex2) {
    bool success = false;

    if (vertex1 > -1 && vertex2 > -1 && vertex1 != vertex2) {
        int v1_index = -1;
        Data vertex1_data {-1, ""};

        int v2_index = -1;
        Data vertex2_data {-1, ""};

        Data vertex_search {-1, ""};

        for (int i = 0; i < vertex_count && (v1_index == -1 || v2_index == -1); i++) {
            graph[i]->getHead(&vertex_search);

            if (vertex_search.id == vertex1) {
                v1_index = i;
                vertex1_data = vertex_search;
            }

            else if (vertex_search.id == vertex2) {
                v2_index = i;
                vertex2_data = vertex_search;
            }
        }

        if (v1_index != -1 && v2_index != -1) {
            success = graph[v1_index]->addNode(vertex2_data.id, &vertex2_data.data);
            success *= graph[v2_index]->addNode(vertex1_data.id, &vertex1_data.data);

            edge_count += success;
        }
    }
    return success;
}

/*********************
* Name: removeEdge
* Parameters: vertex1 (int) vertex2 (int)
* Returns: bool
* removes edge from graph
**********************/
bool Graph::removeEdge(int vertex1, int vertex2) {
    bool success = false;

    if (vertex1 > -1 && vertex2 > -1 && vertex1 != vertex2) {
        int v1_index = -1;
        int v2_index = -1;

        Data vertex_search{-1, ""};

        for (int i = 0; i < vertex_count && (v1_index == -1 || v2_index == -1); i++) {
            graph[i]->getHead(&vertex_search);

            if (vertex_search.id == vertex1) {v1_index = i;}

            else if (vertex_search.id == vertex2) {v2_index = i;}
        }

        if (v1_index != -1 && v2_index != -1) {
            success = graph[v1_index]->deleteNode(vertex2);
            success *= graph[v2_index]->deleteNode(vertex1);

            edge_count -= success;
        }
    }

    return success;
}

/*********************
* Name: removeVertex
* Parameters: id (int
* Returns: bool
* removes a vertex and all of its edges from the graph
**********************/
bool Graph::removeVertex(int id) {
    bool success = false;

    if (id > -1) {
        Data vertex_search{-1, ""};
        int i = 0;

        for (; i < vertex_count && vertex_search.id != id; i++) {graph[i]->getHead(&vertex_search);}

        if (vertex_search.id == id) {
            i--;

            std::vector<int> delete_edges;
            graph[i]->getIdsAsVector(delete_edges);

            int numberOfEdges = graph[i]->getCount() -1;

            for (int j = 0; j < numberOfEdges; ++j) {removeEdge(id, delete_edges[j]);}

            delete graph[i];
            graph.erase(graph.begin() + i);

            success = true;
            vertex_count -= 1;
        }
    }
    return success;
}

/*********************
* Name: clear
* Parameters: None
* Returns: bool
* removes all edges and vertecies from the graph
**********************/
bool Graph::clear() {
    int size = vertex_count;

    for (int i = 0; i < size; ++i) {delete graph[i];}

    vertex_count = 0;
    edge_count = 0;
    graph.clear();

    return graph.empty();
}

/*********************
* Name: isEmpty
* Parameters: None
* Returns: bool
* returns t/f depending on if any nodes or edges exist
**********************/
bool Graph::isEmpty() {return vertex_count == 0 && edge_count == 0;}

/*********************
* Name: edgeCount
* Parameters: None
* Returns: int
* returns the amount of edges the graph has
**********************/
int Graph::edgeCount() {return edge_count;}


/*********************
* Name: VertexCount
* Parameters: None
* Returns: int
* returns the amount of vertices the graph has
**********************/
int Graph::vertexCount() {return vertex_count;}

/*********************
* Name: contains
* Parameters: id (int)
* Returns: bool
* returns t/f depending on if the id in the graph exists
**********************/
bool Graph::contains(int id) {
    Data vertex_search {-1, ""};

    if (id > -1) {for (int i = 0; i < vertex_count && vertex_search.id != id; ++i) {graph[i]->getHead(&vertex_search);}}

    return vertex_search.id == id;
}

/*********************
* Name: getVertex
* Parameters: id (int), data (Data pbr)
* Returns: bool
* returns t/f depending on if the id in the graph is found and returns the data to caller
* gives junk data if not found
**********************/
bool Graph::getVertex(int id, Data &data) {
    Data vertex_search {-1, ""};

    if (id > -1) {
        for (int i = 0; i < vertex_count && vertex_search.id != id; ++i) {
            graph[i]->getHead(&vertex_search);
        }

        if (vertex_search.id != id) {
            vertex_search.id = -1;
            vertex_search.data = "";
        }
    }
    data = vertex_search;

    return data.id == id;
}

/*********************
* Name: depthFirstSearch
* Parameters: int (id)
* Returns: bool
* recursively does DFS traversal through graph and outputs data.
* returns false if starting id does not exist.
* post traversal, print inaccessible node to console
**********************/
bool Graph::depthFirstSearch(int id) {
    bool success = id > -1 && contains(id);

    if (success) {
        std::vector<bool> visited(vertex_count, false);

        depthFirstSearch(id, visited);
        cout << endl;

        for (int i = 0; i < vertex_count; ++i) {
            if (!visited[i]) {
                Data data;
                graph[i]->getHead(&data);
                cout << "This vertex was not connected to the given vertex and could not be traversed:"
                     << "\nID: " << data.id
                     << "\nData: " << data.data
                     << endl << endl;
            }
        }
    }

    return success;
}

/*********************
* Name: depthFirstSearch
* Parameters: id (int), visited (pbr vector of bools)
* Returns: None
* Private method called recurisively. Does DFS traversal and prints to console
**********************/
void Graph::depthFirstSearch(int id, std::vector<bool> &visited) {
    int vertexIndex = -1;
    Data data;

    if (getVertexIndexAndData(id, vertexIndex, data) && !visited[vertexIndex]) {
        cout << "ID: " << data.id << " Data: " << data.data << endl;
        visited[vertexIndex] = true;

        std::vector<int> ids;
        graph[vertexIndex]->getIdsAsVector(ids);
        unsigned int edges = ids.size();

        for (int i = 0; i < edges; ++i) {depthFirstSearch(ids[i], visited);}
    }
}

/*********************
* Name: getVertexIndexAndData
* Parameters: id (int), index (int pbr), data (Data pbr)
* Returns: bool
* Private helper method that gets the data and index of the specified vertex
**********************/
bool Graph::getVertexIndexAndData(int id, int &index, Data& data) {
    int i = 0;
    bool success = true;

    for (; i < vertex_count && data.id != id; ++i) {graph[i]->getHead(&data);}

    if (data.id != id) {
        i = -1;
        data.id = -1;
        data.data = "";
        success = false;
    }
    index = i -1;

    return success;
}

/*********************
* Name: breadthFirstSearch
* Parameters: int (id)
* Returns: bool
* does BFS traversal through graph and outputs data.
* returns false if starting id does not exist.
* post traversal, prints inaccessible nodes to console
**********************/
bool Graph::breadthFirstSearch(int id) {
    bool success = id > -1 && contains(id);
    std::queue<Data> visiting;

    if (success) {
        std::vector<int> visited(vertex_count, 0);

        Data data;
        int startingVertexIndex = -1;

        getVertexIndexAndData(id, startingVertexIndex, data);
        int vertexIndex = startingVertexIndex;

        visiting.push(data);
        visited[startingVertexIndex] = 1;

        while (!visiting.empty()) {
            data = visiting.front(); // Use front() instead of pop() to access the front element
            visiting.pop();

            cout << "ID: " << data.id << " Data: " << data.data << endl;

            std::vector<int> ids;
            graph[vertexIndex]->getIdsAsVector(ids);

            unsigned int size = ids.size();

            for (int i = 0; i < size; ++i) {
                bool gotIndex = getVertexIndexAndData(ids[i], vertexIndex, data);

                if (gotIndex && !visited[vertexIndex]) {
                    visiting.push(data);
                    visited[vertexIndex] = 1;
                }
            }
        }

        cout << endl;

        for (int i = 0; i < vertex_count; ++i) {
            if (visited[i] == 0) {
                graph[i]->getHead(&data);
                cout << "This vertex was not connected to the given vertex and could not be traversed:"
                     << "\nID: " << data.id
                     << "\nData: " << data.data
                     << endl << endl;
            }
        }
    }
    return success;
}

/*********************
* Name: edgeExists
* Parameters: vertex1 (int), vertex2 (int)
* Returns: bool
* determines if there is an edge between two vertexes if there is returns true
**********************/
bool Graph::edgeExists(int vertex1, int vertex2) {
    bool success = false;

    if (vertex1 > -1 && vertex2 > -1 && vertex1 != vertex2) {
        Data vertex_search;

        int i = 0;

        for (; i < vertex_count && vertex_search.id != vertex1; ++i) {graph[i]->getHead(&vertex_search);}

        if (vertex_search.id == vertex1) {success = graph[i - 1]->exists(vertex2);}
    }

    return success;
}

//destructor
Graph::~Graph() {clear();}


