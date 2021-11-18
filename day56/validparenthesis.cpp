#include<iostream>
#include<stack>
#include<string>
using namespace std;

int validparenthesis(string str){
    if(str == "" || str.length()==0 || str[0]==')' || str[0]=='}' || str[0]==']'){
        return false;
    }
    stack<char> stk;
    stk.push(str[0]);
    for(int i=1; i<str.length(); i++){
        if(!stk.empty()){
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                stk.push(str[i]);
            }else if(str[i]==')' && stk.top()=='('){
                stk.pop();
            }else if(str[i]=='}' && stk.top()=='{'){
                stk.pop();
            }else if(str[i]==']' && stk.top()=='['){
                stk.pop();
            }else{
                return false;
            }
        }else{
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                stk.push(str[i]);
            }else{
                return false;
            }
        }
    }
    if(!stk.empty()){
        return false;
    }
return true;
}

int main(){
    cout<<validparenthesis("()")<<endl;
return 0;
}