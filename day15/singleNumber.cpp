#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singleNumber(vector<int> arr){
    sort(arr.begin(), arr.end());
    int i=0, n=arr.size();
    while(i<n-1){
        if(arr[i] != arr[i+1]){
            return arr[i];
        }else{
            i=i+2;
        }
    }
return arr[n-1];
}

