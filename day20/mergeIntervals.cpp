#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for(auto it : intervals){
        if(temp[1] >= it[0]){
            temp[1] = max(temp[1], it[1]);
        }else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
return ans;
}
