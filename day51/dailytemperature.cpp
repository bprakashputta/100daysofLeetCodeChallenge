class Solution {
public:
    // This solution will lead to TLE
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=temp.size()-2; i>=0; i--){
            if(temp[i] < temp[i+1]){
                ans.push_back(1);
            }else{
                int days=0;
                bool chk=false;
                for(int j=i+1; j<temp.size(); j++){
                    if(temp[i] < temp[j]){
                        ans.push_back(days+1);
                        chk = true;
                        break;
                    }else{
                        days++;
                    }
                }
                if(chk==false){
                    ans.push_back(0);
                }
            }
        }
        reverse(ans.begin(), ans.end());
    return ans;
    }
};