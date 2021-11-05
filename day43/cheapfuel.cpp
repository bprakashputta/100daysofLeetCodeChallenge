#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int X,Y,A,B,K;
	    cin>>X>>Y>>A>>B>>K;
	    X = X + (K*A);
	    Y = Y + (K*B);
	    if(X==Y){
	        cout<<"SAME PRICE"<<endl;
	    }else if(X<Y){
	        cout<<"PETROL"<<endl;
	    }else{
	        cout<<"DIESEL"<<endl;
	    }
	}
	return 0;
}
