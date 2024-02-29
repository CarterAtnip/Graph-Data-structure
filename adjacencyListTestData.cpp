/*********************
* Name: Carter Atnip
* Programming III: Data structures
* adjacency list test data class logic
**********************/

#include "adjacencyListTestData.h"

// default constructor
AdjacencyListTestData::AdjacencyListTestData() {
    int_array = new int[ADJ_TEST_DATA_BASE];
    str_array = new string [ADJ_TEST_DATA_BASE];

    fillIntArray();
    fillStrArray();
}

//constructor
AdjacencyListTestData::AdjacencyListTestData(int id) {
    if (id < TEST_DATA_OFFSET) {id = ADJ_TEST_DATA_BASE;}

    int_array = new int[id];
    str_array = new string [id];

    fillIntArray();
    fillStrArray();
}

/*********************
* Name: fillIntArray
* Parameters: None
* Returns: None
* fills int array and forces the second to last int to be a duplicate and the last to be -1
**********************/
void AdjacencyListTestData::fillIntArray() {
    int size = sizeof int_array - 2;

    for (int i = 0; i < size; ++i) {int_array[i] = rand() % MAXID + 1;}

    int_array[size] = int_array[0];
    int_array[size + 1] = -1;
}

/*********************
* Name: fillStrArray
* Parameters: None
* Returns: None
* fills string array and forces the last string to be empty
**********************/
void AdjacencyListTestData::fillStrArray() {
    int size = sizeof(str_array) - 1;

    int rnum;

    for (int i = 0; i < size; ++i) {
        rnum = rand() % ADJ_TEST_DATA_BASE;

        char *buffer = new char[rnum+1];

        int j = 0;
        for(; j < rnum; j++){
            buffer[j] = (rand() % ('Z' - 'A' + 1)) + 'A';
        }
        buffer[j] = '\0';

        str_array[i] = buffer;

        delete[] buffer;
    }

    str_array[size] = "";
}

/*********************
* Name: displayTestData
* Parameters: None
* Returns: None
* displays test data to console
**********************/
void AdjacencyListTestData::displayTestData() {
    int size = sizeof int_array;

    cout << "Displaying Test Data for AdjacencyList class..." << endl;

    for (int i = 0; i < size; ++i) {
        cout << i << ": " << int_array[i] << " : " << str_array[i] << endl;
    }
    cout << endl;
}

/*********************
* Name: addNodeTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results to console
**********************/
void AdjacencyListTestData::addNodeTest(AdjacencyList &list, bool verbose) {
    int size = sizeof int_array;

    if (verbose) {
        cout << "Beginning AddNode test..." << endl;

        for (int i = 0; i < size; ++i) {
            cout << "Adding " << int_array[i] << " : ";

            if (list.addNode(int_array[i], &str_array[i])) {cout << "success" << endl;}

            else {cout << "invalid data" << endl;}
        }
        cout << endl;
    }

    else {for (int i = 0; i < size; ++i) {list.addNode(int_array[i], &str_array[i]);}}
}

/*********************
* Name: deleteNodeTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console
**********************/
void AdjacencyListTestData::deleteNodeTest(AdjacencyList &list, bool verbose) {
    if (verbose) {
        cout << "Beginning Random Delete test..." << endl;

        int loops = (sizeof int_array) * OVERTEST;

        for (int i = 0; i < loops; ++i) {
            int rand_num = rand() % MAXID + 1;

            if (list.deleteNode(rand_num)) {cout << "Deleted " << rand_num << endl;}

            else {cout << "Invalid id " << rand_num << endl;}

        }

        cout << "Random Delete test complete\n" << endl;

        cout << "Beginning Remove Tail test..." << endl;

        int i = (sizeof int_array) - 2;

        for (; i >= 0; --i) {

            if (list.deleteNode(int_array[i])) {cout << "Deleted " << int_array[i] << endl;}

            else {cout << "Invalid id " << int_array[i]<< endl;}

        }

        cout << endl;
    } else {
        int loops = (sizeof int_array) * OVERTEST;


        for (int i = 0; i < loops; ++i) {
            int rand_num = rand() % MAXID + 1;
            list.deleteNode(rand_num);
        }

    }
}

/*********************
* Name: clearListTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console
**********************/
void AdjacencyListTestData::clearListTest(AdjacencyList &list, bool verbose) {
    if (verbose) {
        cout << "Beginning Clear List test..." << endl;

        cout << "Testing partially filled list clear" << endl;

        if (list.clearList()) {cout << "Successfully cleared list" << endl;}
        else {cout << "list clear failed" << endl;}

        cout << endl;

        cout << "Testing empty list clear" << endl;

        if (list.clearList()) {cout << "Successfully cleared list" << endl;}
        else {cout << "list clear failed" << endl;}

        cout << endl;

        cout << "Filling and test list clear on full list" << endl;

        addNodeTest(list);

        if (list.clearList()) {cout << "Successfully cleared list" << endl;}
        else {cout << "list clear failed" << endl;}

        cout << endl;

        cout << "Refilling list for next test..." << endl;

        addNodeTest(list);

        cout << endl;
    } else {
        list.clearList();

        list.clearList();
        addNodeTest(list);

        list.clearList();
        addNodeTest(list);
    }
}

/*********************
* Name: getHeadTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console.
* Stress tests getNode method
**********************/
void AdjacencyListTestData::getHeadTest(AdjacencyList &list, bool verbose) {
    Data temp;

    if (verbose) {
        cout << "Beginning Get Head test..." << endl;

        cout << "Testing on list with nodes" << endl;

        if (list.getHead(&temp)) {cout << "Found Head\t ID: " << temp.id << " Data: " << temp.data << endl;}
        else {cout << "No Head found\t ID: " << temp.id << " Data: " << temp.data << endl;}

        cout << endl;

        list.clearList();

        cout << "Testing on list without nodes" << endl;

        if (list.getHead(&temp)) {cout << "Found Head\t ID: " << temp.id << " Data: " << temp.data << endl;}
        else {cout << "No Head found\t ID: " << temp.id << " Data: " << temp.data << endl;}

        cout << endl;

        cout << "Refilling list for next test..." << endl;

        addNodeTest(list);

        cout << endl;
    } else {
        list.getHead(&temp);

        list.clearList();
        list.getHead(&temp);

        addNodeTest(list);
    }
}

/*********************
* Name: getNodeTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console.
* Stress tests getNode method
**********************/
void AdjacencyListTestData::getNodeTest(AdjacencyList &list, bool verbose) {
    Data temp;

    if (verbose) {
        cout << "Beginning Get Node Test..." << endl;

        cout << "Testing random values" << endl;

        int loops = sizeof int_array * OVERTEST;

        for (int i = 0; i < loops; ++i) {
            int rand_num = rand() % MAXID;

            if (list.getNode(rand_num, &temp)) {cout << "Found Node\t ID: " << temp.id << " Data: " << temp.data << endl;}
            else {cout << "No node found for " << rand_num <<"\t ID: " << temp.id << " Data: " << temp.data << endl;}
        }

        cout << endl;

        cout << "Testing values in list" << endl;

        int i = (sizeof int_array) - 2;

        for (; i >= 0; --i) {
            if (list.getNode(int_array[i], &temp)) {cout << "Found Node\t ID: " << temp.id << " Data: " << temp.data << endl;}
            else {cout << "No node found for " << int_array[i] <<"\t ID: " << temp.id << " Data: " << temp.data << endl;}
        }

        cout << endl;

        cout << "Testing empty list" << endl;

        list.clearList();

        if (list.getNode(MAXID, &temp)) {cout << "Found Node\t ID: " << temp.id << " Data: " << temp.data << endl;}
        else {cout << "No node found for " << MAXID <<"\t ID: " << temp.id << " Data: " << temp.data << endl;}

        cout << endl;

        cout << "Refilling list for next test..." << endl;

        addNodeTest(list);

        cout << endl;
    } else {
        int loops = sizeof int_array * OVERTEST;

        for (int i = 0; i < loops; ++i) {
            int rand_num = rand();
            list.getNode(rand_num, &temp);
        }

        int i = (sizeof int_array) - 2;

        for (; i >= 0; --i) {
            list.getNode(int_array[i], &temp);
        }

        list.clearList();

        list.getNode(int_array[i], &temp);

        addNodeTest(list);
    }
}

/*********************
* Name: getCountTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console
**********************/
void AdjacencyListTestData::getCountTest(AdjacencyList &list, bool verbose) {
    if (verbose) {
        cout << "Beginning Get Count test..." << endl;

        cout << "There are " << list.getCount() << " nodes in the list" << endl;
        cout << endl;

        list.clearList();

        cout << "Testing on empty list" << endl;
        cout << "There are " << list.getCount() << " nodes in the list" << endl;
        cout << endl;

        cout << "Refilling list for next test..." << endl;
        cout << endl;

        addNodeTest(list);
    } else {
        list.getCount();

        list.clearList();

        list.getCount();

        addNodeTest(list);
    }
}

/*********************
* Name: existsTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results of deletion to console
**********************/
void AdjacencyListTestData::existsTest(AdjacencyList &list, bool verbose) {
    if (verbose) {
        cout << "Beginning Exists test..." << endl;

        cout << "Testing random values" << endl;

        int loops = sizeof int_array * OVERTEST;

        for (int i = 0; i < loops; ++i) {
            int rand_num = rand() % MAXID;

            if (list.exists(rand_num)) {cout << rand_num <<" : Found Node" << endl;}
            else {cout << rand_num <<" : Nothing Found" << endl;}
        }

        cout << endl;

        cout << "Testing values in list" << endl;

        int i = (sizeof int_array) - 2;

        for (; i >= 0; --i) {
            if (list.exists(int_array[i])) {cout << int_array[i] <<" : Found Node" << endl;}
            else {cout << int_array[i] <<" : Nothing Found" << endl;}
        }

        cout << endl;

        cout << "Testing empty list" << endl;

        list.clearList();

        if (list.exists(int_array[i])) {cout << int_array[i] <<" : Found Node" << endl;}
        else {cout << int_array[i] <<" : Nothing Found" << endl;}

        cout << endl;

        cout << "Refilling list for next test..." << endl;

        addNodeTest(list);

        cout << endl;
    } else {
        int loops = sizeof int_array * OVERTEST;

        for (int i = 0; i < loops; ++i) {
            int rand_num = rand();
            list.exists(rand_num);
        }

        int i = (sizeof int_array) - 2;

        for (; i >= 0; --i) {list.exists(int_array[i]);}

        list.clearList();

        list.exists(int_array[i]);

        addNodeTest(list);
    }
}

/*********************
* Name: printListTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results
**********************/
void AdjacencyListTestData::printListTest(AdjacencyList &list, bool verbose) {
    if (verbose) {
        cout << "Beginning Print List test..." << endl;

        cout << "Testing on list with nodes" << endl;
        list.printList(verbose);

        list.clearList();

        cout << "Testing on list with  without nodes" << endl;
        list.printList(verbose);

        cout << endl;

        cout << "Refilling list for next test..." << endl;

        addNodeTest(list);

    } else {
        list.printList(verbose);

        list.clearList();

        list.printList(verbose);

        addNodeTest(list);
    }
}

/*********************
* Name: randomTesting
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results
**********************/
void AdjacencyListTestData::randomTesting(AdjacencyList &list, bool verbose) {
    int loops = sizeof int_array * OVERTEST;

    if (verbose) {
        cout << "Beginning Random testing..." << endl;
        for (int i = 0; i < loops; ++i) {
            int selection = rand() % ADJRANDSELECT;

            switch (selection) {
                case 0:
                    addNodeTest(list, verbose);
                    break;

                case 1:
                    deleteNodeTest(list, verbose);
                    break;

                case 2:
                    clearListTest(list, verbose);
                    break;

                case 3:
                    getHeadTest(list, verbose);
                    break;

                case 4:
                    getNodeTest(list, verbose);
                    break;

                case 5:
                    getCountTest(list, verbose);
                    break;

                case 6:
                    existsTest(list, verbose);
                    break;

                case 7:
                    printListTest(list, verbose);
                    break;
            }
        }
        cout << endl;

    } else {
        for (int i = 0; i < loops; ++i) {
            int selection = rand() % ADJRANDSELECT;

            switch (selection) {
                case 0:
                    addNodeTest(list, verbose);
                    break;

                case 1:
                    deleteNodeTest(list, verbose);
                    break;

                case 2:
                    clearListTest(list, verbose);
                    break;

                case 3:
                    getHeadTest(list, verbose);
                    break;

                case 4:
                    getNodeTest(list, verbose);
                    break;

                case 5:
                    getCountTest(list, verbose);
                    break;

                case 6:
                    existsTest(list, verbose);
                    break;

                case 7:
                    printListTest(list, verbose);
                    break;
            }
        }
    }
}

/*********************
* Name: fullTest
* Parameters: list (pbr AdjacencyList), verbose (bool default false)
* Returns: None
* if verbose is set to true, displays test results
**********************/
void AdjacencyListTestData::fullTest(AdjacencyList& list, bool verbose) {
    if(verbose) {
        displayTestData();

        addNodeTest(list, verbose);

        deleteNodeTest(list, verbose);

        clearListTest(list, verbose);

        getHeadTest(list, verbose);

        getNodeTest(list, verbose);

        getCountTest(list, verbose);

        existsTest(list, verbose);

        printListTest(list, verbose);

        randomTesting(list, verbose);

    } else {
        addNodeTest(list, verbose);

        deleteNodeTest(list, verbose);

        clearListTest(list, verbose);

        getHeadTest(list, verbose);

        getNodeTest(list, verbose);

        getCountTest(list, verbose);

        existsTest(list, verbose);

        printListTest(list, verbose);

        randomTesting(list, verbose);
    }
}

//destructor
AdjacencyListTestData::~AdjacencyListTestData() {
    delete[] str_array;
    delete[] int_array;
}
