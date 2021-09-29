#include<iostream>
#include<map>
#include<string>
using namespace std;

bool isAnagram(string s, string t) {
    map<char,int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }

    map<char, int> lp;
    for(int i=0; i<t.length(); i++){
        // if s doesnt contain element 
        //  of t, then return false
        if(mp[t[i]]==0){
            return false;
        }
        lp[t[i]]++;
    }
    // Checking if all characters of t 
    // are present in both s and t
    for(int i=0; i<t.length(); i++){
        if(mp[t[i]] != lp[t[i]]){
            return false;
        }
    }
    // Checking if all characters of s
    // are present in both s and t
    for(int i=0; i<s.length(); i++){
        if(mp[s[i]] != lp[s[i]]){
            return false;
        }
    }
return true;
}
