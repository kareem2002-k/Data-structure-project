#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

typedef int ElementType;

class List
{
private:
    class Node
    {
    public:
        ElementType data;
        Node *next;

        Node() : next(0) {}

        Node(ElementType dataValue) : data(dataValue), next(0) {}
    };

    typedef Node *NodePointer;

public:
    List() : first(0), mySize(0) {}

    List(const List &origList) : first(0), mySize(origList.mySize)
    {
        if (mySize == 0)
            return;

        NodePointer origPtr, newPtr;
        first = new Node(origList.first->data);

        newPtr = first;
        origPtr = origList.first->next;

        while (origPtr != 0)
        {
            newPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            newPtr = newPtr->next;
        }
    }

    ~List()
    {
        NodePointer prev = first;
        NodePointer ptr;
        while (prev != 0)
        {
            ptr = prev->next;
            delete prev;
            prev = ptr;
        }
        first = 0;
        mySize = 0;
    }

    bool empty()
    {
        return mySize == 0;
    }

    const List &operator=(const List &rightSide)
    {
        mySize = rightSide.mySize;

        if (mySize == 0)
        {
            this->~List();
            first = 0;
            return *this;
        }
        if (this != &rightSide)
        {
            this->~List();
            NodePointer origPtr, newPtr;
            first = new Node(rightSide.first->data);

            newPtr = first;
            origPtr = rightSide.first->next;

            while (origPtr != 0)
            {
                newPtr->next = new Node(origPtr->data);
                origPtr = origPtr->next;
                newPtr = newPtr->next;
            }
        }
        return *this;
    }

    void insert(ElementType dataVal, int index)
    {
        if (index < 0 || index > mySize)
        {
            cerr << "Illegal location to insert -- " << index << endl;
            return;
        }
        mySize++;
        NodePointer newNodePtr = new Node(dataVal),
                    predNodePtr = first;
        if (index == 0)
        {
            newNodePtr->next = first;
            first = newNodePtr;
        }
        else
        {
            for (int i = 1; i < index; i++)
            {
                predNodePtr = predNodePtr->next;
            }
            newNodePtr->next = predNodePtr->next;
            predNodePtr->next = newNodePtr;
        }
    }

    void erase(int index)
    {
        if (index < 0 || index >= mySize)
        {
            cerr << "Illegal location to delete -- " << index << endl;
            return;
        }
        mySize--;
        NodePointer ptr, predPtr = first;
        if (index == 0)
        {
            ptr = first;
            first = first->next;
            delete ptr;
        }
        else
        {
            for (int i = 1; i < index; i++)
            {
                predPtr = predPtr->next;
            }
            ptr = predPtr->next;
            predPtr->next = ptr->next;
            delete ptr;
        }
    }

    void split_list(NodePointer head, NodePointer &evenlist, NodePointer &oddlist)
    {
        if (head == NULL)
        {
            return;
        }
        NodePointer main = head, evenptr = evenlist, oddptr = oddlist;

        while (main != NULL)
        {
            if (main->data % 2 == 0)
            {
                if (evenlist == NULL)
                {
                    evenlist = new Node(main->data);
                    evenptr = evenlist;
                }
                else
                {
                    evenptr->next = new Node(main->data);
                    evenptr = evenptr->next;
                }
            }
            else
            {
                if (oddlist == NULL)
                {
                    oddlist = new Node(main->data);
                    oddptr = oddlist;
                }
                else
                {
                    oddptr->next = new Node(main->data);
                    oddptr = oddptr->next;
                }
            }
            main = main->next;
        }
    }

    int search(ElementType dataVal)
    {
        int loc;
        NodePointer tempPtr = first;
        for (loc = 0; loc < mySize; loc++)
            if (tempPtr->data == dataVal)
                return loc;
            else
                tempPtr = tempPtr->next;
        return -1;
    }

    void display(ostream &out) const
    {
        NodePointer ptr = first;
        while (ptr != 0)
        {
            out << ptr->data << "  ";
            ptr = ptr->next;
        }
    }

    friend ostream &operator<<(ostream &out, const List &aList)
    {
        aList.display(out);
        return out;
    }

    NodePointer &getfirst()
    {
        return this->first;
    }

    void setfirst(NodePointer newfirst)
    {
        this->first = newfirst;
    }

    bool operator==(const List &list2)
    {
        if (mySize != list2.mySize)
            return false;

        NodePointer ptr1 = first;
        NodePointer ptr2 = list2.first;

        for (int i = 0; i < mySize; i++)
        {
            if (ptr1->data != ptr2->data)
            {
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }

    void PrintAllIndices(ElementType key)
    {
        NodePointer ptr = first;
        int i = 0;

        cout << "indices: ";
        while (ptr != nullptr)
        {
            if (ptr->data == key)
            {
                cout << i << " ";
            }
            ptr = ptr->next;
            i++;
        }
    }

    void Reverse()
    {
        if (first == nullptr || first->next == nullptr)
        {
            cerr << "*** nothing to reverse" << endl;
            return;
        }

        NodePointer previous = nullptr;
        NodePointer current = first;
        NodePointer next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        first = previous;
    }

private:
    NodePointer first;
    int mySize;
};

ostream &operator<<(ostream &out, const List &aList);
