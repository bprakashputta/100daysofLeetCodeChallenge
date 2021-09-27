#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> reshapeMatrix(vector<vector<int>> mat, int r, int c){
    // reshape the matrix into given r rows and c columns matrix
    if(r*c != mat.size()*mat[0].size()){
        return mat;
    }
    vector<vector<int>> arr(r, vector<int>(c,0));
    int p=0,q=0;
    // idea is to traverse the arr over r,c
    // and use two pointers p,q to access the array
    // while iterating and copy the data
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j] = mat[p][q];
            if(q+1 == mat[p].size()){
                q=0;
                p++;
            }else{
                q++;
            }
        }
    }
return arr;
}

int main(){

}