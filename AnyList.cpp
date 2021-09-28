//
// Created by Guido Asbun on 9/7/21.
//

#include "AnyList.h"

#include <iostream>
using namespace std;

/* ***************************** Lab 3 ***************************** */
/* **************** Overloaded insertion << operator **************** */
ostream& operator<<(ostream& out, const AnyList& list)
{
    if (!list.count)
        cerr << "List is empty.";
    else
    {
        Node* current = list.first;
        while (current != nullptr)
        {
            out << current->getData() << " ";
            current = current->getNext();
        }
    }
    return out;
}

/* ***************************** Lab 3 ***************************** */
/* ****************          Copy Constructor        **************** */
AnyList::AnyList(const AnyList& otherList)
{
    count = otherList.count;

    Node *other =  otherList.first;
    first = nullptr;

    while (other)
    {
        Node* newNode = new Node(other->getData(), nullptr);

        if (first == nullptr)
            first = newNode;
        else
        {
            Node* current = first;

            while (current->getNext() != nullptr)
                current = current->getNext();

            current->setNext(newNode);
        }

        other = other->getNext();
    }
}

/* ***************************** Lab 3 ***************************** */
/* **************** Overloaded comparison Operator == **************** */
bool AnyList::operator==(const AnyList& otherList) const
{
    if (count != otherList.count)
        return false;
    else
    {
        Node *compare = first;
        Node *equalTo =  otherList.first;
        while (equalTo)
        {
            if (compare->getData() != equalTo->getData())
                return false;
            else
            {
                compare = compare->getNext();
                equalTo = equalTo->getNext();
            }
        }
    }
    return true;
}

void AnyList::insertFront(int newData)
{
    first = new Node(newData, first);
    ++count;
}

void AnyList::print() const
{
    if (first == nullptr)
        // Check if the list is empty.
        // You can also use: if (count == 0)
        cerr << "List is empty.";
        // Use cerr, instead of cout. Why?
    else
    {
        Node *current = first;
        // Create a pointer to traverse the list.
        // This pointer will point to the first node in the list.

        while (current != nullptr)
            // While the current pointer is NOT a nullptr,
            // that is, while the current pointer has not reached
            // the end of the list.
        {
            // Output the data.
            cout << current->getData() << " ";
            // Move the pointer current forward.
            current = current->getNext();
        }
    }
}

// This function does not delete the
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{
    Node  *temp = first;
    // Pointer to delete the node, which
    // starts by pointing to the first node.

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    // Update the count outside the loop.
    count = 0;
}

void AnyList::insertBack(int newData)
{
    Node* ptrToNewNode = new Node(newData, nullptr);

    if (first == nullptr)
        first = ptrToNewNode;
    else
    {
        Node* current = first;

        while (current->getNext() != nullptr)
            current = current->getNext();

        current->setNext(ptrToNewNode);
    }
    ++count;
}

int AnyList::getNumOfElements() const {
    return count;
}

bool AnyList::search(int key) const
{
    if (count == 0)
    {
        cerr << "The list is empty.\n";
        return false;
    }
    else
    {
        Node* current = first;

        while (current != nullptr)
        {
            if (current->getData() == key)
                return true;
            else
                current = current->getNext();
        }
        return false;
    }
}

void AnyList::replaceData(int oldKey, int newKey)
{
    bool found = false; // to stop the loop when key is found
    Node* current = first;
    while (current != nullptr && !found)
    {
        if (current->getData() == oldKey)
            found = true;
        else
            current = current->getNext();
    }
    if (current == nullptr) // key was found
        cout << "Element is not in the list." << endl;
    else
        current->setData(newKey);
}

void AnyList::deleteElem(int elem)
{
    if (count == 0)
        cerr << "List is empty." << endl;
    else
    {
        if (first->getData() == elem)
        {
            Node* current = first;
            first = first->getNext();
            delete current;
            current = nullptr;
            --count;
        } else
        {
            bool found = false;
            Node* trailCurrent = first;
            Node* current = first->getNext();

            while (!found && current != nullptr)
            {
                if (current->getData() == elem)
                {
                    trailCurrent->setNext(current->getNext());
                    delete current;
                    current = nullptr;
                    --count;
                    found = true;
                } else
                {
                    trailCurrent = current;
                    current = current->getNext();
                }
            }
            if (!found)
                cout << "Element " << elem << " is not in the list." << endl;
        }
    }
}

int AnyList::getFirstElem() const
{
    return first->getData();
}

bool AnyList::isEmpty() const
{
    return !count;
}

void AnyList::deleteLastNode()
{

    if (count == 0) // Checks to see if list is empty
        cerr << "Cannot delete from an empty list.\n";
    else if (count == 1) // If list has only one Node
    {
        delete first;
        first = nullptr;
        --count;
    } else
    {
        // Creates the Temporary leading node pointer
        Node* temp = first;
        // Creates the previous node pointer behind the leading node.
        Node* pre = first;
        // Loop to set temp node to last, which will be deleted
        // And pre to the last node.
        while(temp->getNext())
        {
            pre = temp;
            temp = temp->getNext();
        }
        // Sets pre as the last node and its next to nullptr
        pre->setNext(temp->getNext());
        // Deletes the temp node pointer.
        delete temp;
        temp = nullptr;
        --count;
    }
}

bool AnyList::compareLists(const AnyList &compareList) const
{
    // Checks to see if both lists are the same size, if not, returns false
    if (compareList.count != count)
        return false;
    else
    {
        Node* firstList = first;
        Node* secondList = compareList.first;

        // Iterates through the lists, they are assumed to be the same length
        while (firstList)
        {
            // Compares the data of both lists, if not the same, returns false
            if (firstList->getData() != secondList->getData())
                return false;
            else
            {
                // Increments to the nextPtr of the lists
                firstList = firstList->getNext();
                secondList = secondList->getNext();
            }
        }
        return true;
    }
}

AnyList::~AnyList()
{
    clearList();
}





/*
 *
 *     count = otherList.count;
    Node *other =  otherList.first;

    while (other != nullptr)
    {
        Node* newNode = new Node(other->getData(), nullptr);

        if (first == nullptr)
            first = newNode;
        else
        {
            Node* current = first;

            while (current->getNext() != nullptr)
                current = current->getNext();

            current->setNext(newNode);
        }
        other = other->getNext();
    }
 *
 * */