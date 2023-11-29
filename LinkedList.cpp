#include <iostream>
#include "BankAccount.h"

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    int size;  // Added data member to track the size

public:
    Node<T>* head;
public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Copy constructor
    LinkedList(const LinkedList& other) {
        head = copyList(other.head);
        size = other.size;
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            head = copyList(other.head);
            size = other.size;
        }
        return *this;
    }

    // Output operator
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);

    // Insert function at a specific index
    void insert(int index, const T& value) {
        if (index < 0 || index > size) {
            std::cerr << "Error: Index out of bounds" << std::endl;
            return;
        }

        if (index == 0 || head == nullptr) {
            // Insert at the beginning
            Node<T>* newNode = new Node<T>(value);
            newNode->next = head;
            head = newNode;
        } else {
            // Insert at a specific index
            Node<T>* current = head;
            for (int i = 0; i < index - 1 && current != nullptr; ++i) {
                current = current->next;
            }

            if (current != nullptr) {
                Node<T>* newNode = new Node<T>(value);
                newNode->next = current->next;
                current->next = newNode;
            } else {
                std::cerr << "Error: Index out of bounds" << std::endl;
                return;
            }
        }

        size++;
    }

    // Erase function at a specific index
    void erase(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Error: Index out of bounds" << std::endl;
            return;
        }

        if (index == 0) {
            // Erase at the beginning
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        } else {
            // Erase at a specific index
            Node<T>* current = head;
            Node<T>* previous = nullptr;
            for (int i = 0; i < index && current != nullptr; ++i) {
                previous = current;
                current = current->next;
            }

            if (current != nullptr) {
                previous->next = current->next;
                delete current;
            } else {
                std::cerr << "Error: Index out of bounds" << std::endl;
                return;
            }
        }

        size--;
    }

    // Append function to insert at the end
    void append(const T& value) {
        insert(size, value);
    }

    // Clear function to delete all nodes
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }

    // Function to get the size of the list
    int getSize() const {
        return size;
    }

private:
    // Helper function for deep copy
    Node<T>* copyList(const Node<T>* source) {
        if (source == nullptr) {
            return nullptr;
        }

        Node<T>* newHead = new Node<T>(source->data);
        Node<T>* currentNewNode = newHead;
        const Node<T>* currentSourceNode = source->next;

        while (currentSourceNode != nullptr) {
            currentNewNode->next = new Node<T>(currentSourceNode->data);
            currentNewNode = currentNewNode->next;
            currentSourceNode = currentSourceNode->next;
        }

        return newHead;
    }
};

// Output operator implementation

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    Node<T>* current = list.head;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}
