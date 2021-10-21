#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string multiply(string s1, string s2) {
        string result = "", num1, num2;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int l1=s1.length();
        int l2=s2.length();
        if(l1>l2){
            num1 = s2;
            num2 = s1;
        }else{
            num1 = s1;
            num2 = s2;
        }
        int mcarry = 0;
        for(int i=0; i<num1.length(); i++){
            int x = num1[i]-'0';
            string row = "";
            for(int j=0; j<num2.length(); j++){
                int mul = num2[j]-'0';
                cout<<"x:"<<x<<endl;
                cout<<"mul:"<<mul<<endl;
                int prod = (x*mul) + mcarry;
                mcarry = 0;
                if(prod > 9){
                    mcarry = prod/10;
                    prod = prod%10;
                }
                row += to_string(prod);
            }
            if(mcarry != 0){
                row += to_string(mcarry);
            }
            // Commented out the reverse to add
            // row and result from reverse directly
            // reverse(row.begin(), row.end());
            cout<<"rowin:"<<row<<endl;
            for(int k=0; k<i; k++){
                row = "0" + row;
            }
            cout<<"row:"<<row<<endl;
            // Now we have to add this 
            // row prod to the result
            // we have result, and row
            if(result == ""){
                result = row;
            }else{
                int acarry=0;
                string temp = "";
                for(int k=0; k<result.length(); k++){
                    int rw1 = row[k]-'0';
                    int re1 = result[k]-'0';
                    int d = rw1 + re1 + acarry;
                    acarry = 0;
                    if(d>9){
                        acarry = 1;
                        d = d%10;
                    }
                    temp += to_string(d);
                }
                for(int k=result.length(); k<row.length(); k++){
                    int re1 = result[k]-'0';
                    int d = re1 + acarry;
                    acarry = 0;
                    if(acarry>9){
                        acarry = 1;
                        d = d%10;
                    }
                    temp += to_string(d);
                }
                
                result = temp;
            }
        }
        // reverse(result.begin(), result.end());
    return result;
    }
};