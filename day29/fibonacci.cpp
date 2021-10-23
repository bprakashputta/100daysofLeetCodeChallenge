#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3+2, MOD = 1e9+7;

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

int main(){
    int n = 5;
    vector<int> fib(n+1,-1);
    int f = fibo(n, fib);
    cout<<f<<endl;
return 0;
}
