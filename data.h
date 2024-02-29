/*********************
* Name: data.h
* Programming III: Data structures
* data file for creating nodes
**********************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
};

#endif //DATA_H