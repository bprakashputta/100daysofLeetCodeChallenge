class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0,mins = 0;
        // vector<int> pre(nums.size());
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mins = min({mins, sum});
            cout<<"sum: "<<sum<<", minsum: "<<mins<<endl;
        }
        return 1-mins;
    }
};