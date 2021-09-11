//
// Created by Guido Asbun on 9/7/21.
//

#ifndef ANYLIST_H
#define ANYLIST_H

#include <string> // Need to include for nullptr.

class Node
{
public:
    // Default constructor
    Node() : data(0), ptrToNext(nullptr) {}

    // Overloaded constructor
    Node(int theData, Node *newPtrToNext)
            : data(theData), ptrToNext(newPtrToNext){}

    // Function getPtrToNext returns the address of the next node
    Node* getPtrToNext() const { return ptrToNext; }

    // Function get getData returns the int value stored in the node
    int getData( ) const { return data; }

    //  Function setData overwrites the int value stored in
    // the node with a given value.
    void setData(int theData) { data = theData; }

    // Function set PtrToNext overWrites the address stored in
    // the node with a given address
    void setPtrToNext(Node *newPtrToNext)
    { ptrToNext = newPtrToNext; }

    // Destructor
    ~Node(){}
private:
    // An int stored in the node
    int data;

    // A pointer storing the address of the next node.
    Node *ptrToNext; // Pointer that points to next node.
};


class AnyList
{
public:
    AnyList() : ptrToFirst(nullptr), count(0) {}

    void insertFront(int);

    void print() const;

    void clearList();

    ~AnyList();

private:
    // Pointer to point to the first node in the list.
    Node *ptrToFirst;

    // Variable to keep track of number of nodes in the list.
    int count;

};
#endif //WEEK2LESSON1_ANYLIST_H
