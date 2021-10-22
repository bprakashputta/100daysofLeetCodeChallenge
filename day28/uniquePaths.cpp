#include<iostream>
#include<vector>
using namespace std;

// Recursive Solution
int path(int m, int n, int i, int j){
    if(i==m-1&&j==n-1){
        return 1;
    }else if(i>=m || j>=n){
        return 0;
    }
    return path(m,n,i+1,j)+path(m,n,i,j+1); 
}

// Dynamic Programming Approach
int dpath(int m, int n, int i, int j, vector<vector<int>>& dp){
    if(i==m-1 && j==n-1){
        return 1;
    }else if(i>=m || j>=n){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }else{
        dp[i][j] = dpath(m,n,i+1,j,dp) + dpath(m,n,i,j+1,dp);
        return dp[i][j];
    }
}


int uniquePaths(int m, int n){
    // return path(m, n, 0, 0);
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // return dpath(m,n,0,0,dp);

    // In the problem to reach the end
    // we are taking m-1 rights, and n-1 downs
    // 
    int N = m+n-2;
    int r = m-1;
    double res = 1;
    for(int i=1; i<=r; i++){
        res = res*(N-r+i)/i;
    }
return (int)res;
}