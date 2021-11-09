#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;


// This solutions runs into TLE as it uses 3-nested for loops
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // This is an interesting problem
        
        vector<int> res;
        for(int i=0; i<puzzles.size(); i++){
            string puzzle = puzzles[i];
            int count = 0;
            // find frequency of characters of puzzle
            map<char,int> pz;
            for(int k=0; k<puzzle.length(); k++){
                pz[puzzle[k]]++;
                // cout<<"puzz: "<<puzzle<<endl;
                // cout<<pz[puzzle[k]]<<endl;
            }

            // iterate over the words 
            for(int j=0; j<words.size(); j++){
                // if word contains first letter of puzzle
                map<char,int> wrd;
                // find frequency of characters in word
                string word = words[j];
                for(int k=0; k<word.length(); k++){
                    wrd[word[k]]++;
                }

                // if first letter of puzzle exists in word
                if(wrd[puzzle[0]]>0){
                    
                    bool chk = true;
                    for(int k=0; k<word.length(); k++){
                        // cout<<puzzle<<", "<<"word[k]: "<<word[k]<<", "<<endl;
                        if(pz[word[k]]==0){
                            chk = false;
                            break;
                        }
                    }
                    if(chk==true){
                        count++;
                    }
                }
            }
            res.push_back(count);
        }
    return res;
    }
};