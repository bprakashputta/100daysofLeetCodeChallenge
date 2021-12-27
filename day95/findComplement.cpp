class Solution {
public:
    int findComplement(int num) {
        int tmp = num;
        int ans=0;
        int i=0;
        while(tmp>0){
            int rem = tmp%2;
            if(rem==0){
                ans += 1*pow(2,i);
                i++;
            }else{
                // ans += 0*pow(2,i);
                i++;
            }
            tmp = tmp/2;
        }
    return ans;
    }
};