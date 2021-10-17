#include<iostream>
#include<string>
#include<vector>
using namespace std;

// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

vector<int> splitString(string s, vector<int>&nums){
    // vector<int> nums;
    string word = "";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        cout<<"ch:"<<ch<<endl;
        if(s[i] == ' '){
            cout<<word<<endl;
            if(word[0]>='0' && word[0]<='9'){
                nums.push_back(stoi(word));
            }
            word = "";
        }else if(i==s.length()-1){
                word = word + ch;
            if(word[0]>='0' && word[0]<='9'){
                nums.push_back(stoi(word));
            }
            word = "";
        }else{
            word = word + ch;
        }
    }
    return nums;
}


bool areNumbersAscending(string s) {
    bool res;
    vector<int> nums;
    splitString(s, nums);
    for(int i=1; i<nums.size(); i++){
        cout<<"nums[i]:"<<nums[i]<<endl;
    }
    for(int i=1; i<nums.size(); i++){
        if(nums[i] > nums[i-1]){
            res = true;
        }else{
            return false;
        }
    }
return res;
}
