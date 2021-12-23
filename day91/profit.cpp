#include<iostream>
#include<string>
using namespace std;

class Product{
    public:
        float a,x,y;
};

void profitLoss(int n, Product p[]){
    // Write code here
    float pl = 0, sp=0, cp=0;
    float totalG =0;
    for(int i=0; i<n; i++){
        cp = p[i].a;
        sp = cp*(100+p[i].x)/100;
        float discount = sp*(p[i].y)/100;
        pl = sp-discount;
        totalG += (pl-cp);
        cout<<"cp:"<<cp<<", sp:"<<sp<<", pl:"<<pl<<", totalG:"<<totalG<<endl;
    }
    if(totalG>0){
        cout<<"Profit "<<(int)totalG<<endl;
    }else{
        cout<<"Loss "<<(-1)*(int)totalG<<endl;
    }
}

int main(){
    int n;
    float a,x,y;
    cin>>n;
    Product p[n];
    for(int i=0; i<n;i++){
        cin>>a>>x>>y;
        p[i].a = a;
        p[i].x = x;
        p[i].y = y;
    }
    profitLoss(n,p);
return 0;
}