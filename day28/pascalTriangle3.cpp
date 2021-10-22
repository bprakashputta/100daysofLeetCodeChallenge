#include<iostream>
#include<vector>
using namespace std;

// Return the whole pascal triangle of n rows
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans(n);
    // ans[0]
    for(int i=0; i<n; i++){
        ans[i].resize(i+1);
        ans[0][0] = 1;
        if(i==0){
            continue;
        }
        for(int j=0; j<i+1; j++){
            if(j==0||j==i){
                ans[i][j] = 1;
            }else{
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
    }
return ans;
}

// Brute Force Approach
vector<int> pascalTriangleRow(int n){
    vector<vector<int>> pascalTriangle = pascalTriangle(n);
return pascalTriangle[n-1];
}
// Optimal Approach
vector<int> pascalTriangleRow(int n){
    vector<int> ans(n+1);
    ans[0] = 1;
    ans[n] = 1;
    int res = 1;
    for(int i=1; i<=n; i++){
        res = res*(n-i);
        res = res/(i);
        ans[i] = res;
    } 
return ans;
}

int pascalTriangleRowElement(int n, int r){
    double res = 1;
    for(int i=1; i<=r; i++){
        res = res*(n-r+i)/i;
    }
return (int)res;
}

int main(){
    int n=5;
    vector<vector<int>> pascal1 = pascalTriangle(n);
    vector<int> pascalRow1 = pascalTriangleRow(n);
    int pascalRowElement = pascalTrianlgeRowElement(n,n-2);
}