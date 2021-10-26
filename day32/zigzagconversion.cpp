#include<iostream>
#include<string>
using namespace std;

/*

P   A   H   N     0   4   8    12          
A P L S I I G     1 3 5 7 9 11 13     
Y   I   R         2   6   10            
This string is given to us in input as s="PAYPALISHIRING", and we need to convert it to row-wise string s = "PAHNAPLSIIGYIR"

P     I    N      0     6       12          
A   L S  I G      1   5 7    11 13           
Y A   H R         2 4   8 10              
P     I           3     9                     

*/

string zigzagConversion(string s, int numRows){
    string res = "";
    for(int i=0; i<numRows; i++){
        int j=i;
        if(j%2==0){
            while(j<s.length()){
                res += s[j];
                j = j+(2*numRows)-2;
            }
        }else{
            while(j<s.length()){
                res += s[j];
                j = j+(2);
            }
        }
    }
return res;
}

int main(){
    string str = "PAYPALISHIRING";
    cout<<zigzagConversion(str, 4)<<endl;
}