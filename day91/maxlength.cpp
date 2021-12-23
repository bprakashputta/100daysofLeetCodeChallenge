// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int sum=0, len=0, mxl=0;
        for(int i=0; i<A.size(); i++){
            sum += A[i];
            if(sum==0){
                mxl = i+1;
            }else{
                if(mp.find(sum)!=mp.end()){
                    mxl = max({mxl, i-mp[sum]});
                }else{
                    mp[sum] = i;                
                }   
            }
        }
    return mxl;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends