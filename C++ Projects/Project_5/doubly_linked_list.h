#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList{
    public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        
    }
    
    void push(int data);
    void pop();
    int size() const;
    void print();
    int& at (int idx) const;
    void insert(int data, int pos);
    void remove(int pos);
    ~DoublyLinkedList();
    void operator=(const DoublyLinkedList& rhs);
    
    private:
    Node* head;
    Node* tail;
};

#endif