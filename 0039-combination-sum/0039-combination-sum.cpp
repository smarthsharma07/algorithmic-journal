class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& candidates, int start, int remaining) {
        if (remaining==0){
            ans.push_back(curr);
            return;
        }
        if (remaining<0){
            return;
        }
        for (int i = start; i<candidates.size();i++){
            curr.push_back(candidates[i]);
            backtrack(candidates, i, remaining - candidates[i]);
            curr.pop_back();
        }
    }    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,0,target);
        return ans;
    }
};