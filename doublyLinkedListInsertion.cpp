#include<iostream>
using namespace std;

struct DoublyLinkedListNode{
    int data;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode(int x){
        data = x;
    }
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if(llist == NULL){
        return new DoublyLinkedListNode(data);
    }
    if(llist->data > data){
        DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
        temp->next = llist;
        return temp;
    }
    
    DoublyLinkedListNode* head = llist;
    DoublyLinkedListNode* tail = NULL;
    while(head!=NULL && head->data<data){
        tail = head;
        head = head->next;
    }
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
    tail->next = temp;
    temp->prev = tail;
    if(head==NULL){
        return llist;
    }
    temp->next = head;
    head->prev = temp;
return llist;
}