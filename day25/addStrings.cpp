#include<iostream>
#include<string>
using namespace std;
// This code doesn't work for long strings of the power 
// greater than 10^9
string addStrings(string num1, string num2) {
    int n1 = stoi(num1);
    int n2 = stoi(num2);
    return to_string(n1+n2);
}

// An optimised code to tackle numbers with any number 
// of digits
string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int n1=num1.length();
    int n2=num2.length();
    string result = "";
    int carry = 0;
    if(n1>=n2){
        carry=0;
        for(int i=0; i< num2.length(); i++){
            int d1 = num1[i] - '0';
            int d2 = num2[i] - '0';
            int d = d1+d2+carry;
            carry=0;
            if(d>9){
                carry = 1;
                d = d-10;
            }else{
                carry = 0;
            }
            result += to_string(d);
        }
        for(int i=num2.length(); i<num1.length(); i++){
            int d1 = num1[i] - '0';
            int d = d1 + carry;
            carry=0;
            if(d>9){
                carry = 1;
                d=d-10;
            }else{
                carry = 0;
            }
            result += to_string(d);
        }
    }else{
        carry = 0;
        for(int i=0; i<num1.length(); i++){
            int d1 = num1[i] - '0';
            int d2 = num2[i] - '0';
            int d = d1+d2+carry;
            carry=0;
            if(d>9){
                carry = 1;
                d = d-10;
            }else{
                carry = 0;
            }
            result += to_string(d);
        }
        for(int i=num1.length(); i<num2.length(); i++){
            int d1 = num2[i] - '0';
            int d = d1 + carry;
            carry=0;
            if(d>9){
                carry = 1;
                d=d-10;
            }else{
                carry = 0;
            }
            result += to_string(d);
        }
    }
    if(carry == 1){
        result += "1";
    }
    reverse(result.begin(), result.end());
return result;
}