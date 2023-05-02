#include <iostream>
#include "singly_linked_list.h"

using namespace std;

void foo(){
    SinglyLinkedList sll;
    
    sll.push_back(5);
    sll.push_back(8);
    sll.push_back(10);
    
    SinglyLinkedList sll2 = sll;
    sll2.push_back(3);
    sll2.push_back(2);
    
    sll2 = sll;
    
    for(int i = 0; i < sll.size(); i++){
        cout << sll2.at(i) << endl;
    }
}

int main(){
    /*Node* head = nullptr;
    
    push_back(head, 2);
    push_back(head, 10);
    push_back(head, 3);
    push_back(head, 40);
    
    remove(head,1);
    
    cout << at(head, 0) << endl;
    cout << at(head, 1) << endl;
    cout << at(head, 2) << endl;

    /*
    head = new Node;
    
    head->data = 2;
    head->next = nullptr;
    
    (head->next) = new Node;
    (head->next)->next = nullptr;
    (head->next)->data = 10;
    */
    
    foo();
    foo();
    
    return 0;
}