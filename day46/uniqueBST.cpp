#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bstpairs(long long int n, vector<long long int>& f){
        if(n==0||n==1){
            return 1;
        }
        bstpairs(n-1, f);
        int val=0;
        for(int i=1; i<=n; i++){
            int l = i-1;
            int r = n-i;
            val += f[l]*f[r];
        }
        f[n] = val;
    return f[n];
    }
    int numTrees(int n) {
        vector<long long int> f(n+1, -1);
        if(n<2){
            return n;
        }
        f[0]=1;
        f[1]=1;
        bstpairs(n, f);
        return f[n];
    }
};