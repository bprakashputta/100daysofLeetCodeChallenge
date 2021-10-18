#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
    // check if string starts with closed bracket
    if(s[0]==')' || s[0]=='}' || s[0]==']'){
        return false;
    }
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1; i<s.length(); i++){
        if(!stk.empty()){
            if(s[i]=='(' || s[i] == '{' || s[i]=='['){
                stk.push(s[i]);
            }else if(s[i]==')' && stk.top()=='('){
                stk.pop();
            }else if(s[i]=='}' && stk.top()=='{'){
                stk.pop();
            }else if(s[i]==']' && stk.top()=='['){
                stk.pop();
            }else{
                return false;
            }
        }else{
            if(s[i]=='(' || s[i] == '{' || s[i]=='['){
                stk.push(s[i]);
            }else{
                return false;
            }
        }
    }
    bool ans;
    if(stk.empty()){
        ans = true;
    }else{
        ans = false;
    }
return ans;
}