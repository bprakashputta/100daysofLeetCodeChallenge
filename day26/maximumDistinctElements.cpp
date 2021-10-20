#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://www.codechef.com/SNCKQL21/problems/MAXDISTKT/

typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    ll test;
    cin>>test;
    while(test--){
        ll N;
        cin>>N;
        vector<pair<ll,ll>> b(N);
        for(ll i=0; i<N; i++){
            cin>>b[i].first;
            b[i].second = i;
        }
        // sort the array
        sort(b.begin(), b.end());
        vector<ll> ans(N);\
        ll sm = 0;
        for(ll i=0; i<N; i++){
            if(sm < b[i].first){
                ans[b[i].second] = sm;
                sm++;
            }
            // else it doesnt matter which number it is
            // if the sm < b[i].first condition is not 
            // satisfied
        }

        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
return 0;
}