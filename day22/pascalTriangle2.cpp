#include<iostream>
#include<vector>
using namespace std;

// This is Pascal Triangle Variation Problem
vector<int> rowIndexthRow(int rowIndex){
    vector<vector<int>> ans(rowIndex+1);
    for(int i=0; i<=rowIndex; i++){
        ans[i].resize(i+1);
        for(int j=0; j<i+1; j++){
            if(j==0||j==i){
                ans[i][j] = 1;
            }else{
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
    }
return ans[rowIndex];
}