#include<iostream>
using namespace std;

int thirdMax(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int i=nums.size()-1;
	int p=0;
	vector<int> ans(3);
	ans[p] = nums[nums.size()-1];
	i--;
	while(i>=0){
	    if(nums[i] != ans[p] && p<3){
		p++;
		ans[p] = nums[i];
	    }
	    i--;
	    if(p==2){
		break;
	    }
	}
	if(p<2){
	    return ans[0];
	}

	return ans[2];
}
