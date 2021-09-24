#include<bits/stdc++.h>
#include<vector>
using namespace std;


// array size less than 10^5
// array values are in the region [-10000, 10000]
int maxSubArray(vector<int> arr){
    int mx = INT_MIN;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        // checking if the sum + current num
        // is going to increase sum or decrease sum
        if(sum+arr[i] >= arr[i]){
            sum += arr[i];
        }else{
            sum = arr[i];
        }

        // check if max value is 
        // less than current sum
        if(mx < sum){
            mx = sum;
        }
    }
return mx;
}

int main(){
    
}