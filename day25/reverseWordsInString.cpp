#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/

string reverseWords(string s) {
    string word="";
    string result="";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(s[i]==' '){
            reverse(word.begin(), word.end());
            result += word;
            result += " ";
            word = "";
        }else if(i==s.length()-1){
            word += ch;
            reverse(word.begin(), word.end());
            result += word;
        }else{
            word += ch;
        }
    }
return result;
}