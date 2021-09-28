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
    Node() : data(0), next(nullptr) {}

    // Overloaded constructor
    Node(int theData, Node *newPtrToNext)
            : data(theData), next(newPtrToNext){}

    // Function getNext returns the address of the next node
    Node* getNext() const { return next; }

    // Function get getData returns the int value stored in the node
    int getData( ) const { return data; }

    //  Function setData overwrites the int value stored in
    // the node with a given value.
    void setData(int theData) { data = theData; }

    // Function set PtrToNext overWrites the address stored in
    // the node with a given address
    void setNext(Node *newPtrToNext)
    { next = newPtrToNext; }

    // Destructor
    ~Node(){}
private:
    // An int stored in the node
    int data;

    // A pointer storing the address of the next node.
    Node *next; // Pointer that points to next node.
};


class AnyList
{

    /* ***************************** Lab 3 ***************************** */
    /* **************** Overloaded insertion << operator **************** */
    friend std::ostream& operator<<(std::ostream& out, const  AnyList& list);

public:
    AnyList() : first(nullptr), count(0) {}

    /* ***************************** Lab 3 ***************************** */
    /* ****************          Copy Constructor        **************** */

    AnyList(const AnyList& otherList);

    /* ***************************** Lab 3 ***************************** */
    /* **************** Overloaded comparison Operator **************** */

    bool operator==(const AnyList&) const;

    void insertFront(int);

    void print() const;

    void clearList();

    void insertBack(int);

    int getNumOfElements() const;

    bool search(int key) const;

    void replaceData(int oldKey, int newKey);

    void deleteElem(int elem);

    int getFirstElem() const;

    bool isEmpty() const;

    void deleteLastNode();

    bool compareLists(const AnyList& compareList) const;

    ~AnyList();

private:
    // Pointer to point to the first node in the list.
    Node *first;

    // Variable to keep track of number of nodes in the list.
    int count;

};
#endif //WEEK2LESSON1_ANYLIST_H
