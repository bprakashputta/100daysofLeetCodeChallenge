class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>&pair, vector<vector<int>>& pairs){
        if(target < 0 || index==candidates.size()){
            return;
        }else if(target == 0){
            pairs.push_back(pair);
            // pair.clear();
            return;
        }else{
            pair.push_back(candidates[index]);
            solve(index, candidates, target-candidates[index], pair, pairs);
            pair.pop_back();
            solve(index+1, candidates, target, pair, pairs);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> pairs;
        vector<int> pair;
        solve(0, candidates, target, pair, pairs);
    return pairs;
    }
};