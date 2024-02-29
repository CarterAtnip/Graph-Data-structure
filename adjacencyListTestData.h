/*********************
* Name: Carter Atnip
* Programming III: Data structures
* adjacency list test data class header
**********************/

#ifndef ADJACENCYLISTTESTDATA_H
#define ADJACENCYLISTTESTDATA_H

#define ADJ_TEST_DATA_BASE 8
#define TEST_DATA_OFFSET 1
#define MAXID 100
#define OVERTEST 10
#define ADJRANDSELECT 8

#include <stdlib.h>
#include <string>
#include <iostream>
#include "data.h"
#include "adjacencyList.h"

using std::cout;
using std::endl;
using std::string;


class AdjacencyListTestData {
public:
    //default constructor
    AdjacencyListTestData();

    //primary constructor
    explicit AdjacencyListTestData(int);

    void displayTestData();

    void addNodeTest(AdjacencyList&, bool = false);

    void deleteNodeTest(AdjacencyList&, bool = false);

    void clearListTest(AdjacencyList&, bool = false);

    void getHeadTest(AdjacencyList&, bool = false);

    void getNodeTest(AdjacencyList&, bool = false);

    void getCountTest(AdjacencyList&, bool = false);

    void existsTest(AdjacencyList&, bool = false);

    void printListTest(AdjacencyList&, bool = false);

    void randomTesting(AdjacencyList&, bool = false);

    void fullTest(AdjacencyList&, bool = false);

    ~AdjacencyListTestData();

private:
    void fillIntArray();

    void fillStrArray();

    int *int_array;

    string *str_array;
};

#endif //ADJACENCYLISTTESTDATA_H