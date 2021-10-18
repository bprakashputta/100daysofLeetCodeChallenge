#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    for(int i=0; i<mat.size(); i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    
    for(int i=0; i<4; i++){
        if(mat == target){
            return true;
        }else{
            rotate(mat);
        }
    }
return false;
}


