#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* llist1, SinglyLinkedListNode* llist2) {
    if(llist1==NULL || llist2==NULL){
        return 0;
    }
    SinglyLinkedListNode* head1 = llist1;
    SinglyLinkedListNode* head2 = llist2;
    while(head1!=NULL && head2!=NULL){
        SinglyLinkedListNode* temp = head2;
        while(temp!=NULL){    
            if(head1 == temp){
                return head1->data;
            }
            temp = temp->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    head1 = llist1;
    head2 = llist2;
    while(head1!=NULL && head2!=NULL){
        SinglyLinkedListNode* temp = head1;
        while(temp!=NULL){    
            if(head2 == temp){
                return head2->data;
            }
            temp = temp->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
return -1;
}

int main(){
    
}