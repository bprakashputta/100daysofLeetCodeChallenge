#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        // N number of biscuts and a,b are factors of multiplication of biscuits
        double n,a,b;
        cin>>n>>a>>b;
        // total cost of buying n biscuts is, cost = a*(x*x) + b*((n-x)*(n-x));
        // we have to buy n biscuits with minimum cost
        // so take differential of the cost and find x
        int x = (n*b)/(a+b);
        // after simplifying 
        // cost becomes cost = (n*n*a*b)/(a+b);
        // our task would be to return ceil of the cost
        double cost = (n*n*a*b)/(a+b);
        cout<<"cost: "<<cost<<endl;
        cout<<"ceil: "<<ceil(cost)<<endl;
    }
return 0;
}