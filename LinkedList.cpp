#include <iostream>
#include <string>
#include "BankAccount.cpp"
using namespace std;

class List {
private:
    class Node {
    public:
        BankAccount data;
        Node* next;

        Node(const BankAccount& dataValue) : data(dataValue), next(nullptr) {}
    };

    typedef Node* NodePointer;

public:
    List() : first(nullptr), mySize(0) {}

    ~List() {
        NodePointer prev = first;
        NodePointer ptr;
        while (prev != nullptr) {
            ptr = prev->next;
            delete prev;
            prev = ptr;
        }
        first = nullptr;
        mySize = 0;
    }

    // Copy constructor
    List(const List& origList) : first(nullptr), mySize(origList.mySize) {
        if (mySize == 0)
            return;

        NodePointer origPtr, newPtr;
        first = new Node(origList.first->data);

        newPtr = first;
        origPtr = origList.first->next;

        while (origPtr != nullptr) {
            newPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            newPtr = newPtr->next;
        }
    }

    // Assignment operator
    const List& operator=(const List& rightSide) {
        mySize = rightSide.mySize;

        if (mySize == 0) {
            this->~List();
            first = nullptr;
            return *this;
        }
        if (this != &rightSide) {
            this->~List();
            NodePointer origPtr, newPtr;
            first = new Node(rightSide.first->data);

            newPtr = first;
            origPtr = rightSide.first->next;

            while (origPtr != nullptr) {
                newPtr->next = new Node(origPtr->data);
                origPtr = origPtr->next;
                newPtr = newPtr->next;
            }
        }
        return *this;
    }

    // Member functions

    void insert(const BankAccount& dataVal, int index) {
        if (index < 0 || index > mySize) {
            cerr << "Illegal location to insert -- " << index << endl;
            return;
        }

        mySize++;
        NodePointer newNodePtr = new Node(dataVal),
                    predNodePtr = first;
        if (index == 0) {
            newNodePtr->next = first;
            first = newNodePtr;
        } else {
            for (int i = 1; i < index; i++) {
                predNodePtr = predNodePtr->next;
            }
            newNodePtr->next = predNodePtr->next;
            predNodePtr->next = newNodePtr;
        }
    }

   // add to the end of the list
    void append(const BankAccount& dataVal) {
        insert(dataVal, mySize);
    }

    void erase(int index) {
        if (index < 0 || index >= mySize) {
            cerr << "Illegal location to delete -- " << index << endl;
            return;
        }
        mySize--;
        NodePointer ptr, predPtr = first;
        if (index == 0) {
            ptr = first;
            first = first->next;
            delete ptr;
        } else {
            for (int i = 1; i < index; i++) {
                predPtr = predPtr->next;
            }
            ptr = predPtr->next;
            predPtr->next = ptr->next;
            delete ptr;
        }
    }

    // Other member functions

    void display(ostream& out) const {
        NodePointer ptr = first;
        while (ptr != nullptr) {
            out << ptr->data.getBalance() << "  "; // Displaying balance as an example
            ptr = ptr->next;
        }
    }

    friend ostream& operator<<(ostream& out, const List& aList) {
        aList.display(out);
        return out;
    }

private:
    NodePointer first;
    int mySize;
};

