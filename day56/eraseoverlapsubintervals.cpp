#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int eraseOverlappingSubIntervals(vector<vector<int>> intervals){
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];

    int count=0;
    for(auto it:intervals){
        if(temp[1] <= it[0]){
            temp = it;
        }else if(temp[1] <= it[1]){
            // a and b intersect each other
            // we will delete b in this case
            count++;
        }else if(temp[1] > it[1]){
            // b is a subpart of a
            // we will delete a in this case
            temp = it;
            count++;
        }
    }
return count-1;
}