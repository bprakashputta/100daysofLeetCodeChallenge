#include<iost>
using namespace std;

struct Node{
    /* data */
    int data;
    Node* next;
};


bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL){
        return false;
    }
    Node* n1=head;
    Node* n2=head->next;
    while(n1!=n2){
        if(n1==NULL || n2==NULL || n2->next==NULL){
            return false;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
return true;
}