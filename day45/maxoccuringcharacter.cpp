#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

// int maxoccurringcharacter(string str){
//     map<char,int>mp;
//     int count=0, mxc=-1;
//     for(int i=0; i<str.length(); i++){
//         cout<<str[i]<<endl;
//         mp[str[i]]++;
//     }

//     for(auto it:mp){
//         cout<<it.first<<" : "<<it.second<<endl;
//         if(mxc<=it.second){
//             count = mxc;
//             mxc = it.second;
//         }
//     }
//     if(mxc == count){
//         return 0;
//     }
// return mxc;
// }

int maxoccurringcharacter(char* str){
    char c;
    for(int i = 0;str[i] != '\0';i++){
        c = str[i];
        cout << c;
        mp[c]++;
    }

    for(auto it:mp){
        cout<<it.first<<" : "<<it.second<<endl;
        if(mxc<=it.second){
            count = mxc;
            mxc = it.second;
        }
    }
    if(mxc == count){
        return 0;
    }
return mxc;
}

int main(){
    // string str;
    // cin>>str;
    // cout<<maxoccurringcharacter(str)<<endl;
    char* str = "segsefse";
    // cin>>str;
    // cout<<str<<endl;
    cout<<maxoccurringcharacter(str)<<endl; 
return 0;
}