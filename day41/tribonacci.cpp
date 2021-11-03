#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& tib){
        if(n==0){
            return 0;
        }else if(n==1 || n==2){
            return 1;
        }
        
        if(tib[n]!=-1){
            return tib[n];
        }else{
            tib[n] = solve(n-1, tib)+solve(n-2, tib)+solve(n-3, tib);
        }
    return tib[n];
    }
    
    int tribonacci(int n) {
        vector<int> arr(n+1, -1);
    return solve(n, arr);
    }
};