#include<iostream>
using namespace std;

struct List{
    int data;
    List* prev;
    List* next;
};

List* reverseDoublyList(List* llist){
    if(llist==NULL || llist->next==NULL){
        return llist;
    }    
    List* curr = llist;
    List* rev = NULL;
    while(curr!=NULL){
        rev = curr->prev;
        curr->prev = curr->next;
        curr->next = rev;
        curr = curr->prev;
    }
    if(rev != NULL){
        llist = rev->prev;
    }
return llist;
}