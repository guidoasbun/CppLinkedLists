//
// Created by Guido Asbun on 9/7/21.
//

#include "AnyList.h"

#include <iostream>
using namespace std;

void AnyList::insertFront(int newData)
{
    ptrToFirst = new Node(newData, ptrToFirst);
    ++count;
}

void AnyList::print() const
{
    if (ptrToFirst == nullptr)
        // Check if the list is empty.
        // You can also use: if (count == 0)
        cerr << "List is empty.";
        // Use cerr, instead of cout. Why?
    else
    {
        Node *current = ptrToFirst;
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
            current = current->getPtrToNext();
        }
    }
}

// This function does not delete the
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{
    Node  *temp = ptrToFirst;
    // Pointer to delete the node, which
    // starts by pointing to the first node.

    while (ptrToFirst != nullptr)
    {
        ptrToFirst = ptrToFirst->getPtrToNext();
        delete temp;
        temp = ptrToFirst;
    }

    // Update the count outside the loop.
    count = 0;
}

void AnyList::insertBack(int newData)
{
    Node* ptrToNewNode = new Node(newData, nullptr);

    if (ptrToFirst == nullptr)
        ptrToFirst = ptrToNewNode;
    else
    {
        Node* current = ptrToFirst;

        while (current->getPtrToNext() != nullptr)
            current = current->getPtrToNext();

        current->setPtrToNext(ptrToNewNode);
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
        Node* current = ptrToFirst;

        while (current != nullptr)
        {
            if (current->getData() == key)
                return true;
            else
                current = current->getPtrToNext();
        }
        return false;
    }
}

void AnyList::replaceData(int oldKey, int newKey)
{
    bool found = false; // to stop the loop when key is found
    Node* current = ptrToFirst;
    while (current != nullptr && !found)
    {
        if (current->getData() == oldKey)
            found = true;
        else
            current = current->getPtrToNext();
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
        if (ptrToFirst->getData() == elem)
        {
            Node* current = ptrToFirst;
            ptrToFirst = ptrToFirst->getPtrToNext();
            delete current;
            current = nullptr;
            --count;
        } else
        {
            bool found = false;
            Node* trailCurrent = ptrToFirst;
            Node* current = ptrToFirst->getPtrToNext();

            while (!found && current != nullptr)
            {
                if (current->getData() == elem)
                {
                    trailCurrent->setPtrToNext(current->getPtrToNext());
                    delete current;
                    current = nullptr;
                    --count;
                    found = true;
                } else
                {
                    trailCurrent = current;
                    current = current->getPtrToNext();
                }
            }
            if (!found)
                cout << "Element " << elem << " is not in the list." << endl;
        }
    }
}

int AnyList::getFirstElem() const
{
    return ptrToFirst->getData();
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
        delete ptrToFirst;
        ptrToFirst = nullptr;
        --count;
    } else
    {
        // Creates the Temporary leading node pointer
        Node* temp = ptrToFirst;
        // Creates the previous node pointer behind the leading node.
        Node* pre = ptrToFirst;
        // Loop to set temp node to last, which will be deleted
        // And pre to the last node.
        while(temp->getPtrToNext())
        {
            pre = temp;
            temp = temp->getPtrToNext();
        }
        // Sets pre as the last node and its ptrToNext to nullptr
        pre->setPtrToNext(temp->getPtrToNext());
        // Deletes the temp node pointer.
        delete temp;
        temp = nullptr;
        --count;
    }
}

AnyList::~AnyList()
{
    clearList();
}