#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// this method works, but in interview this wouldnt work,
// they will need a solution that is not using sort function
void mergeSortedArrays(vector<int> &nums1, int m, vector<int> &nums2, int n){
    for(int i=m; i<m+n; i++){
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}

// This method will work only when all 
// the elements of both arrays are positive
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m==0&&n!=0){
        nums1 = nums2;
        return;
    }else if(m!=0&&n==0){
        return;
    }
    
    int l1=0, l2=0, s1=m, s2=n;
    while(l2<n && l1<m+n){
        // If n1 <= n2
        // increase l1
        // else n1 > n2
        // move n1 elements 
        // to the right by
        // x places and insert
        // n2 in n1
        if(nums1[l1] <= nums2[l2]&&nums1[l1]!=0){
            l1++;
            s1--;
        }else{
            for(int j=l1+s1; j>l1; j--){
                cout<<"j:"<<j<<", l1:"<<l1<<", nums1[j]:"<<nums1[j]<<endl;
                nums1[j] = nums1[j-1];
                cout<<"j:"<<j<<", l1:"<<l1<<", nums1[j]:"<<nums1[j]<<endl;
            }
            cout<<"nums1[l1]:"<<nums1[l1]<<endl;
            nums1[l1] = nums2[l2];
            cout<<"nums1[l1]:"<<nums1[l1]<<endl;
            l1++;
            l2++;
            s2--;
        }
    }
}

// Works for all ranges of values of elements of arrays
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // for(int i=m; i<m+n; i++){
    //     nums1[i] = nums2[i-m];
    // }
    // sort(nums1.begin(), nums1.end());
    if(m==0&&n!=0){
        nums1 = nums2;
        return;
    }else if(m!=0&&n==0){
        return;
    }
    int l1 = m-1;
    int l2 = n-1;
    int i = m+n-1; 
    while(l1>=0 && l2>=0){
        if(nums1[l1]>=nums2[l2]){
            int temp = nums1[i];
            nums1[i] = nums1[l1];
            nums1[l1] = temp;
            i--;
            l1--;
        }else{
            int temp = nums1[i];
            nums1[i] = nums2[l2];
            nums2[l2] = temp;
            l2--;
            i--;
        }
    }
    // while(l1>=0){
    //     nums1[i] = nums1[l1];
    //     i--;
    //     l1--;
    // }
    while(l2>=0){
        nums1[i] = nums2[l2];
        i--;
        l2--;
    }
}
