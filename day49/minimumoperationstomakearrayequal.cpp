class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = (2*i)+1;
        }
        int num = 0;
        if(n%2==0){
            num = arr[n/2]-1;
        }else{
            num = arr[n/2];
        }
        int ops=0;
        for(int i=0; i<n/2; i++){
            ops += num - arr[i];
        }
    return ops;
    }

    // Without using extra space of array
    int minOperations(int n) {
        // vector<int> arr(n);
        // for(int i=0; i<n; i++){
        //     arr[i] = (2*i)+1;
        // }
        int num = 0;
        if(n%2==0){
            // num = arr[n/2]-1;
            num = 2*(n/2);
        }else{
            // num = arr[n/2];
            num = 2*(n/2)+1;
        }
        int ops=0;
        for(int i=0; i<n/2; i++){
            // ops += num - arr[i];
            ops += num - (2*i)-1;
        }
    return ops;
    }

};