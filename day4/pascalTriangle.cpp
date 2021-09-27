#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int n) {
    vector<vector<int>> arr(n,vector<int>(1,0));
    // int m=1;
    for(int i=1; i<=n; i++){
        arr[i-1].resize(i);
        for(int j=0; j<i; j++){
            if(j==0 || j==i-1){
                arr[i-1][j] = 1; 
            }else{
                arr[i-1][j] = arr[i-2][j-1] + arr[i-2][j]; 
            }
        }
    }
return arr;
}

int main(){
    // print 
    vector<vector<int>> ans = generate(5);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
    }
return 0;
}