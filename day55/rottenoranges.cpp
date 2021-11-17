#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rottenOranges(vector<vector<int>> grid){
    queue<pair<int,int>>rotten;
    int oranges = 0, count = 0, mins=0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] != 0){
                oranges++;
            }
            if(grid[i][j]==2){
                rotten.push({i,j});
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    while(!rotten.empty()){
        int k=rotten.size();
        count += k;
        for(int i=0; i<k; i++){
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for(int p=0; p<4; p++){
                int nx = x + dx[p];
                int ny = y + dy[p];
                if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]!=1){
                    continue;
                }
                grid[nx][ny] = 2;
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty()){
            mins++;
        }
    }
    cout<<count<<" "<<oranges<<endl;
    if(count == oranges){
        return mins;
    }
return -1;
}

int main(){
    vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};
    cout<<rottenOranges(grid)<<endl;
return 0;
}