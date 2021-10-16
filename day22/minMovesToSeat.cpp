#include<iostream>
#include<vector>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    map<int,int> mp;
    
    for(int i=0; i<seats.size(); i++){
        mp[seats[i]]++;
    }
    int moves=0;
    sort(students.begin(), students.end());
    sort(seats.begin(), seats.end());
    for(int i=0; i<students.size(); i++){
        if(mp[students[i]] > 0 && students[i] == seats[i]){
            mp[students[i]]--;
        }else{
            moves += abs(seats[i] - students[i]);
        }
    }
return moves;
}