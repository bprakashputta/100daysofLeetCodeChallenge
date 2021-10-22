#include<iostream>
#include<vector>
using namespace std;

int ncr(int n, int r){
    double res = 1;
    for(int i=1; i<=r; i++){
        res = res*(n-r+i)/i;
    }
return (int)res;
}