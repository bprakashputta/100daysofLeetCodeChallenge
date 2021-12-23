class Solution {
public:
    double myPow(double x, int num) {
        if(num==0){
            return 1;
        }else if(x==0){
            return 0;
        }
        long n = num;
        if(n<0){
            n =-1*n;
        }
        double ans = 1;
        while(n>0){
            if(n%2==1){
                ans = ans*x;
                n=n-1;
            }else{
                x = x*x;
                n=n/2;
            }
        }
        if(num<0){
            return 1/ans;
        }
    return ans;
    }
};