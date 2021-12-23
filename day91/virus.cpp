#include<iostream>
#include<vector>
#include<string>

using namespace std;

int findVirus(string a){
    int res=-1;
    //WRITE YOUR CODE HERE
    char ch = a[0];
    for(int i=0; i<a.length(); i++){
        cout<<"a[i]:"<<a[i]<<endl;
        if(i%2==0){
            if(a[i]==ch){
                res = 1;
            }else{
                res = 0;
                return res;
                // break;
            }
        }
    }
return res;
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        cout<<findVirus(str)<<endl;
    }
return 0;
}