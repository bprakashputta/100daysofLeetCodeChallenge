#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/reverse-string/

void reverseString(vector<char>& s) {
    return reverse(s.begin(), s.end());
}

void reverseString(vector<char>& s){
    int l=0, r=s.size()-1;
    while(l<=r){
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

void reverseString(vector<char>& s) {
    for(int i=0; i<s.size()/2; i++){
        char temp = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = temp;
    }    
}