#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1==NULL && l2==NULL){
        return NULL;
    }else if(l1!=NULL && l2==NULL){
        return l1;
    }else if(l1==NULL && l2!=NULL){
        return l2;
    }
    ListNode* answer;
    ListNode* result=NULL;
    ListNode* num1 = l1;
    ListNode* num2 = l2;
    int carry = 0;
    while(num1!=NULL && num2!=NULL){
        int d = num1->val + num2->val + carry;
        carry = 0;
        if(d>9){
            carry = 1;
            d = d - 10;
        }
        if(result == NULL){
            result = new ListNode(d);
            answer = result;
        }else{
            result->next = new ListNode(d);
            result = result->next;
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    
    while(num1!=NULL){
        int d = num1->val + carry;
        carry = 0;
        if(d>9){
            carry = 1;
            d = d - 10;
        }
        result->next = new ListNode(d);
        result = result->next;
        num1 = num1->next;
    }
    
    while(num2!=NULL){
        int d = num2->val + carry;
        carry = 0;
        if(d>9){
            carry = 1;
            d = d - 10;
        }
        result->next = new ListNode(d);
        result = result->next;
        num2 = num2->next;
    }
    if(carry == 1){
        result->next = new ListNode(carry);
        result = result->next;
    }
return answer;
}