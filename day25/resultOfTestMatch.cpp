#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int res, i=0, ind=0, eng=0;
	    while(i<5){
	        cin>>res;
	        if(res==1){
	            ind++;
	        }else if(res==2){
	            eng++;
	        }else{
	         ind++;
	         eng++;
	        }
	        i++;
	    }
	    if(ind == eng){
	        cout<<"DRAW"<<endl;
	    }else if(ind > eng){
	        cout<<"INDIA"<<endl;
	    }else{
	        cout<<"ENGLAND"<<endl;
	    }
	}
	return 0;
}
