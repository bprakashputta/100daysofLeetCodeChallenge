#include<iostream>
using namespace std;

int firstBadVersion(int n) {
    if(n==1){
        return n;
    }
    int l=1, r=n; 
    int ans = 1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(isBadVersion(mid)==true){
            ans = mid;
            r= mid-1;
        }else{
            l=mid+1;
        }
    }
return ans;
}
