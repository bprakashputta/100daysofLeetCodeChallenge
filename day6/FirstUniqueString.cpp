#include<iostream>
#include<string>
#include<map>
using namespace std;

int firstUniqChar(string s) {
    map<char, int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }
    for(int i=0; i<s.length(); i++){
        // for the first element
        // with frequency of 1 is 
        // our answer
        if(mp[s[i]] == 1){
            return i;
        }
    }
return -1;
}