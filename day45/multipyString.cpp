#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addNums(string s1, string s2){
        cout<<"Adding "<<s1<<", "<<s2<<endl;
        string sum = "";
        int carry = 0;
        string temp = "";
        if(s1.length()<s2.length()){
            temp  = s2;
            s2 = s1;
            s1 = temp;
            temp = "";
        }
        cout<<"Adding "<<s1<<", "<<s2<<endl;
        int p = s1.length()-1;
        for(int j=s2.length()-1; j>=0; j--){
            int a1 = s1[p]-'0';
            p--;
            int a2 = s2[j]-'0';
            int sm = a1+a2+carry;
            carry = 0;
            if(sm>9){
                carry = sm/10;
                sm = sm%10;
            }
            temp = to_string(sm) + temp;
        }
        for(int i=p; i>=0; i--){
            int a1 = s1[i]-'0';
            int sm = a1+carry;
            carry = 0;
            if(sm>9){
                carry = sm/10;
                sm = sm%10;
            }
            temp = to_string(sm) + temp;
        }
        if(carry>0){
            temp = to_string(carry) + temp;
            carry = 0;
        }
    return temp;
    }
    
    string multiply(string s1, string s2) {
        string result = "";
        int carry = 0;
        string temp = "";
        if(s1.length()<s2.length()){
            temp  = s2;
            s2 = s1;
            s1 = temp;
            temp = "";
        }
        // now we surely know that s1 is going to be the longest string
        int counter = 0;
        for(int i=s2.length()-1; i>=0; i--){
            int m2 = s2[i]-'0';
            string tmp = "";
            for(int p=0; p<counter; p++){
                tmp += "0";
            }
            for(int j=s1.length()-1; j>=0; j--){
                int m1 = s1[j]-'0';
                // cout<<m1<<m2<<carry<<endl;
                int prd = (m1*m2) + carry;
                carry = 0;
                if(prd>9){
                    carry = prd/10; 
                    prd = prd%10;
                }
                tmp = to_string(prd) + tmp;
            }
            if(carry>0){
                tmp = to_string(carry) + tmp;
                carry = 0;
            }

            if(counter == 0){
                result = tmp;
            }else{            
                result = addNums(result, tmp);
            }
            // cout<<"result: "<<result<<endl;
            // cout<<"tmp: "<<tmp<<endl;
            counter++;
        }
        if(result[0]=='0'){
            return "0";
        }
    return result;
    }
};