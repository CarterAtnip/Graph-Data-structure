/*********************
* Name: Carter Atnip
* Programming III: Data structures
* logic for adjacency list class
**********************/

#include "adjacencyList.h"

//constructor
AdjacencyList::AdjacencyList() {
    head = NULL;
    count = DEFAULTCOUNT;
}

/*********************
* Name: addNode
* Parameters: id (int), data (string ptr)
* Returns: bool
* adds Node to adjacency list
**********************/
bool AdjacencyList::addNode(int id, string *data) {
    bool success = false;

    if (id > -1 && !data->empty()) {
        Node *newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = *data;
        newNode->next = NULL;

        if (head == NULL) {success = insertHead(newNode);}

        else {success = insertTail(newNode, head);}
    }

    count += success;
    return success;
}

/*********************
* Name: insertHead
* Parameters: newNode (Node ptr)
* Returns: bool
* helper method that adds initial node to list
**********************/
bool AdjacencyList::insertHead(Node *newNode) {
    head = newNode;
    return head->data.id == newNode->data.id;
}


/*********************
* Name: insertTail
* Parameters: newNode (Node ptr), Node (Node ptr)
* Returns: bool
* helper method adds subsequent nodes to adjacency list
**********************/
bool AdjacencyList::insertTail(Node *newNode, Node *current) {
    bool success = false;

    while (current->next != NULL && current->data.id != newNode->data.id) {current = current->next;}

    if (current->data.id != newNode->data.id) {
        current->next = newNode;
        success = true;

    } else {delete newNode;}

    return success;
}

/*********************
* Name: deleteNode
* Parameters: id (int)
* Returns: bool
* deletes an element from the list and returns a bool to indicate success
**********************/
bool AdjacencyList::deleteNode(int id) {
    bool success = false;

    if (head != NULL && id > 0 && count != 1) {
            Node *current = head;

            while (current->next != NULL && current->next->data.id != id) {current = current->next;}

            if (current->next == NULL && current->data.id == id) {
                removeTail(current);
                success = true;
            }

            else if (current->next != NULL && current->next->data.id == id) {
                removeMiddle(current);
                success = true;
            }
        }
    count -= success;
    return success;
}

/*********************
* Name: removeTail
* Parameters: current (Node ptr)
* Returns: bool
* deletes last node from list
**********************/
void AdjacencyList::removeTail(Node *current) {
    delete current->next;
    current->next = NULL;
}

/*********************
* Name: removeMiddle
* Parameters: current (Node ptr)
* Returns: None
* deletes node from last position of adjacency list
**********************/
void AdjacencyList::removeMiddle(Node *current) {
    Node *temp = current->next;
    current->next = current->next->next;

    delete temp;
}

/*********************
* Name: getHead
* Parameters: head_data (data ptr)
* Returns: Bool
* returns the head to caller and returns bool to indicate success
**********************/
bool AdjacencyList::getHead(Data *head_node) {
    bool success = false;

    if (head != NULL) {
        *head_node = head->data;
        success = true;
    } else {
        head_node->id = -1;
        head_node->data = "";
    }

    return success;
}

/*********************
* Name: getNode
* Parameters: int id, data (data ptr)
* Returns: Bool
* returns the data to caller if id is found. Does not get the head use other method to do so
**********************/
bool AdjacencyList::getNode(int id, Data *data) {
    bool success = false;

    if (count > 1) {
        Node* current = head->next;
        while (current != NULL && current->data.id != id) {current = current->next;}

        if (current != NULL) {
            *data = current->data;
            success = true;

        } else {
            data->id = -1;
            data->data = "";
        }
    }

    return success;
}

/*********************
* Name: printList
* Parameters: verbose (bool)
* Returns: None
* prints all nodes in linked list forward
**********************/
void AdjacencyList::printList(bool verbose) {
    Node* current = head;

    if (verbose) {
        while (current != NULL) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }

        cout << endl;
    }

    else {while (current != NULL) {current = current->next;}}
}

/*********************
* Name: getCount
* Parameters: None
* Returns: int
* returns the amount of nodes in the list
**********************/
int AdjacencyList::getCount() {return count;}

/*********************
* Name: clearList
* Parameters: None
* Returns: Bool
* deletes all node from list and returns a bool to indicate success
**********************/
bool AdjacencyList::clearList() {
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    count = DEFAULTCOUNT;

    return head == NULL;
}

/*********************
* Name: exists
* Parameters: id (int)
* Returns: bool
* checks if a Node is in the list based on the id passed,
* returns bool when found/not found
**********************/
bool AdjacencyList::exists(int id) {
    bool success = false;

    if (head != NULL) {
        Node* current = head;
        while (current->next && current->data.id != id) {current = current->next;}
        success = current->data.id == id;
    }

    return success;
}

/*********************
* Name: exists
* Parameters: int_array (int vector pbr)
* Returns: bool
* gets all IDs except the head and puts them into a vector
* returns bool when found/not found
**********************/
bool AdjacencyList::getIdsAsVector(std::vector<int> &int_array) {
    bool success = false;

    if (count > 1) {
        Node *current = head->next;

        while (current) {
            int_array.push_back(current->data.id);
            current = current->next;
        }

        success = true;
    }

    return success;
}

//destructor
AdjacencyList::~AdjacencyList() {clearList();}