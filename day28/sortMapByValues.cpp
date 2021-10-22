#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void sortMapByValues(string s){
    map<char,int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }
    
    vector<pair<char,int>> vec;

    // copy key-value pairs from the map to the vector
    copy(mp.begin(),mp.end(),back_inserter<vector<pair<char,int>>>(vec));

    // sort the vector by increasing the order of its pair's second value
    // if the second value is equal, order by the pair's first value
    sort(vec.begin(), 
        vec.end(),
        [](const pair<char,int> &l, const pair<char,int> &r)
        {
            if (l.second != r.second) {
                return l.second < r.second;
            }

            return l.first < r.first;
        });
}