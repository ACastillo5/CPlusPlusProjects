#include "doubly_linked_list.h"

void DoublyLinkedList::push(int data){
    if(head == nullptr){
        head = new Node;
        tail = new Node;
        
        head->prev = nullptr;
        head->data = data;
        head->next = nullptr;
        return;
    }
    
    Node* NodeNow = head;
    
    while(NodeNow->next != nullptr){
        NodeNow = NodeNow->next;
    }
    
    (*NodeNow).next = new Node;
    (NodeNow->next)->next = nullptr;
    (NodeNow->next)->data = data;
}
    
void DoublyLinkedList::pop(){
        Node* NodeNow = head;
        Node* BeforeNode = tail;
        
        if(head == nullptr && tail == nullptr){
            cout << "No elements to pop" << endl;
            return;
        }
        
        if(NodeNow->next == nullptr && BeforeNode->prev == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        
        while(NodeNow->next->next != nullptr){
            NodeNow = NodeNow->next;
        }
    
        BeforeNode->prev = NodeNow;
        delete NodeNow->next;
        NodeNow->next = nullptr;
    }
    
int DoublyLinkedList::size() const{
    Node* temp = head;
    Node* temp2 = tail;
    int count = 0;
    
    if(temp == nullptr && temp2 == nullptr){
        return count;
    }
    
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    
    return count;
    }
    
void DoublyLinkedList::print(){
    Node *temp = head;
    
    if(temp == nullptr){
        cout << "There is nothing to print" << endl;;
    }
    else{
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    cout << endl;
    }
    
int& DoublyLinkedList::at (int idx) const{
        Node* NodeNow = head;
        Node* BeforeNode = tail;
        
        int i = 0;
        while(i < idx){
            NodeNow = NodeNow->next;
            BeforeNode = BeforeNode ->prev;
            i++;
        }
        
    return NodeNow->data;
    }
    
void DoublyLinkedList::insert(int data, int pos){
        if(pos == 0){
        Node* temp = head;
        Node* temp2 = tail;
        
        head = new Node;
        tail = new Node;
        
        tail->prev = temp2;
        head->data = data;
        head->next = temp;
        
        return;
    }
    
    Node* NodeNow = head;
    Node* BeforeNode = tail;
    
    int i = 0;
    while(i < pos - 1){
        NodeNow = NodeNow->next;
        BeforeNode = BeforeNode->prev;
        i++;
    }
    
    Node* temp = NodeNow->next;
    Node* temp2 = BeforeNode->prev;
    
    NodeNow->next = new Node;
    BeforeNode->prev = new Node;
    
    BeforeNode->prev->prev = NodeNow->next;
    NodeNow->next->data = data;
    NodeNow->next->next = temp;
    }
    
void DoublyLinkedList::remove(int pos){
        if(pos == 0){
            Node* temp = head->next;
            delete head;
            head = temp;
            return;
        }
    
    Node* NodeNow = head;
    Node* BeforeNode = tail;
    
    int i = 0;
    
    while(i < pos - 1){
        NodeNow = NodeNow->next;
        i++;
    }
    
    Node* temp = NodeNow->next->next;
    Node* temp2 = NodeNow->next->prev;
    
    delete NodeNow->next;
    
    BeforeNode->prev = NodeNow;
    NodeNow->next = temp;
    
    }
    
DoublyLinkedList::~DoublyLinkedList(){
        while(head != nullptr && tail != nullptr){
            Node* temp = head->next;
            Node* temp2 = tail->prev;
            delete head;
            delete tail;
            head = temp;
            tail = temp2;
        }
    }
    
void DoublyLinkedList::operator=(const DoublyLinkedList& rhs){
    while(head != nullptr && tail != nullptr){
            Node* temp = head->next;
            Node* temp2 = tail->prev;
            delete head;
            delete tail;
            head = temp;
            tail = temp2;
        }
        
    for(int i = 0; i < rhs.size(); i++){
        push(rhs.at(i));
    }
    }