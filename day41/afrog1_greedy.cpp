#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>& hgts, int i, int end, int cost){
    if(i == end){
        cout<<"i: "<<i<<"cost: "<<cost<<endl;
        return cost;
    }else if(i+1 == end){
        cost += abs(hgts[end]-hgts[i]); 
        i = i+1;
        minCost(hgts, i, end, cost);
    }

    int d2 = abs(hgts[i+2]-hgts[i]);
    int d1 = abs(hgts[i+1]-hgts[i]);
    if(d1>=d2){
        cost += d2;
        i=i+2;
        cout<<"d1: "<<d1<<" d2: "<<d2<<" i: "<<i-2<<" i: "<<i<<endl;
        // minCost(hgts, i, end, cost);
    }else{
        cost += d1;
        i=i+1;
        cout<<"d1: "<<d1<<" d2: "<<d2<<" i: "<<i-1<<" i: "<<i<<endl;
        // minCost(hgts, i, end, cost);
    }
return minCost(hgts, i, end, cost);
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
    int cost = 0;
    cout<<minCost(hgts,0, N-1, cost)<<endl;
    return 0;
}