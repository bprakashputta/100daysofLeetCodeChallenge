#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fibo(int n, vector<int>& fib){
        if(n<2){
            fib[n] = n;
            return fib[n];
        }else{
            if(fib[n] != -1){
                return fib[n];
            }else{
                fib[n] = fibo(n-1, fib) + fibo(n-2, fib);
            }
        }
    return fib[n];
    }

    
    int fib(int n) {
        vector<int> fib(n+1,-1);
        int f = fibo(n, fib);
    return f;
    }
};