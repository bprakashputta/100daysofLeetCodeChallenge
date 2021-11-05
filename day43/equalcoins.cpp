#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
	// your code goes here
	ll test;
	cin>>test;
	while(test--){
	    ll X,Y;
	    cin>>X>>Y;
	    if(Y%2==0){
	        if(X%2==0){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }else{
	        if(X<2){
	            cout<<"NO"<<endl;
	            continue;
	        }
	        
	        if(X%2==0){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }
	}
	return 0;
}
