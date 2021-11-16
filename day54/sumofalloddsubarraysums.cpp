class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prfx(arr.size());
        prfx[0] = arr[0];
        int sum=0;
        for(int i=1; i<arr.size(); i++){
            prfx[i] = arr[i] + prfx[i-1];
        }
        
        for(int i=1; i<=arr.size(); i=i+2){
            // k is sub-array size
            int k = i-1;
            for(int j=0; j<arr.size()-k; j++){
                cout<<"i: "<<i<<", j: "<<j<<", arr[j]: "<<arr[j]<<endl;
                cout<<"prfx[j+k]: "<<prfx[j+k]<<", prfx[j]: "<<prfx[j]<<endl;
                cout<<"prfx[j+k]-prfx[j]:  "<<prfx[j+k]-prfx[j]<<endl;
                if(j==0){
                    sum += prfx[j+k];
                }else{
                    sum += prfx[j+k]-prfx[j-1];    
                }
                cout<<"sum: "<<sum<<endl;
            }
        }
    return sum;
    }
};