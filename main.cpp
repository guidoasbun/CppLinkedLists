#include "AnyList.h"

#include <iostream>
using namespace std;

int main()
{
    AnyList myList;

    myList.insertFront(8);
    myList.insertFront(7);
    myList.insertFront(4);
    myList.insertFront(2);

    cout << "Test: Insertion Operator <<\n";
    cout << myList;
    cout << endl;

    cout << "Inserted: 2 4 7 8\n";
    cout << "List is: ";
    myList.print();
    cout << endl;

    myList.clearList();

//    cout << "\nPrint the list after emptying it...";
//    cout << "\nList is: ";
//    myList.print();
//    cout << endl;
//
//    cout << endl;
    return 0;
}
