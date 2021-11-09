#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){
    string str;
    cin>>str;
    map<int,int> freq;
    for(int i=0; i<=9; i++){
        freq[i]=0;
    }
    for(int i=0; i<str.length(); i++){
        if(str[i]>='0'&&str[i]<='9'){
            freq[str[i]-'0']++;
        }
    }
    // print frequency of characters
    for(auto it:freq){
        cout<<it.second<<" ";
    }
    cout<<endl;
return 0;
}