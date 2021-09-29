#include<iostream>
#include<map>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    map<char, int> mg;
    map<char, int> rn;
    for(int i=0; i<magazine.length(); i++){
        mg[magazine[i]]++;
    }
    for(int i=0; i<ransomNote.length(); i++){
        rn[ransomNote[i]]++;
    }
    
    for(int i=0; i<ransomNote.length(); i++){
        // The logic here is if the character of magazine 
        // is not present in ransomNote or 
        // the number of characters required is 
        // less than number of characters available.
        if(mg[ransomNote[i]] == 0 || mg[ransomNote[i]] < rn[ransomNote[i]]){
            return false;    
        }
    }
return true;
}
