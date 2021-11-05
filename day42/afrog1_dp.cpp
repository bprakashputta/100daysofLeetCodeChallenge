#include<iostream>
#include<vector>
using namespace std;

void minCost(vector<int>& hgts, int i, int end, int cost, int& minc){
    if(i==end){
        return minc;
    }
    int c1 = abs(hgts[i+1]-hgts[i]);
    


}

int main(){
    int N;
    cin>>N;
    vector<int> hgts(N,0);
    for(int i=0; i<N; i++){
        cin>>hgts[i];
    }
    if(N==2){
        cout<<abs(hgts[1]-hgts[0])<<endl;
        return 0;
    }
    int cost = 0, minc = 0;
    minCost(hgts,0, N-1, cost, minc);
    return 0;
}