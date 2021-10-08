#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// storing the frequency of elements of array
// at the same time checking if frequency is 
// greater than n/2 or not.
int majorityElement(vector<int> arr){
    map<int,int> m;
    for(int i=0; i<arr.size(); i++){
        m[arr[i]]++;
        if(m[arr[i]] > (arr.size()/2)){
            return arr[i];
        }
    }
return -1;
}

// Sorting the vector using sort function
// return the mid element, as it is guaranteed
// that atleat one element will occur more than 
// n/2 times.
int majoritYElement(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()/2];
}