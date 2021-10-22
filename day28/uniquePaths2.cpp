#include<iostream>
#include<vector>
using namespace std;

int dpath(int m,int n,int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
    if(i<m && j<n && obstacleGrid[i][j] == 1){
        return 0;
    }
    if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0){
        return 1;
    }else if(i>=m || j>=n){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }else{
        dp[i][j] = dpath(m,n,i+1,j,dp,obstacleGrid)+dpath(m,n,i,j+1,dp,obstacleGrid);
        return dp[i][j];
    }
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return dpath(m,n,0,0,dp,obstacleGrid);
}
