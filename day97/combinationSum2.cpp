class Solution {
public:
    void solve(int index, vector<int>candidates, int original_target,int target, vector<int>&pair, set<vector<int>>&pairs){
        // for(int i=0; i<pair.size(); i++){
        //     cout<<"hi";
        //     cout<<" pair[i]:"<<pair[i]<<", ";
        // }
        cout<<endl;
        if(target<0){
            return;
        }else if(target==0){
            // pairs.push_back(pair);   
            pairs.insert(pair);
            return;
        }else if(index==candidates.size()){
            return;
        }else if(candidates[index] == original_target){
            pairs.insert({candidates[index]});
            return;
         }
        else{
            pair.push_back(candidates[index]);
            solve(index+1, candidates, original_target, target-candidates[index], pair, pairs);
            pair.pop_back();
            solve(index+1, candidates, original_target, target, pair, pairs);
        }
        // if(candidate)
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>pairs;
        vector<vector<int>> result;
        vector<int> pair;
        sort(candidates.begin(), candidates.end());
        // this solve is resulting in TLE due to runtime of O(klogk*2^t) we have an extra logk time here.
        // solve(0, candidates, target, target, pair, pairs);
        for(auto p: pairs){
            result.push_back(p);
        }
    return result;
    }
};



class Solution {
public:
    void solve(int index, vector<int>candidates, int original_target,int target, vector<int>&pair, vector<vector<int>>&pairs){
        if(target==0){
            pairs.push_back(pair);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(candidates[i] > target)break;

            pair.push_back(candidates[i]);   
            solve(i+1, candidates, original_target, target-candidates[i], pair, pairs);
            pair.pop_back();

        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> pairs;
        vector<int> pair;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, target, pair, pairs);
        // for(auto p: pairs){
        //     result.push_back(p);
        // }
    return pairs;
    }
};