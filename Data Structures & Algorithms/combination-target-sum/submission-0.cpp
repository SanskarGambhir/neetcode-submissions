class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> storage;
        combinationSumFunction(0, target, candidates, storage, ans);
        return ans;
    }

    void combinationSumFunction(int index, int target, vector<int>& candidates, vector<int>& storage, vector<vector<int>>& ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(storage);
            }
            return;
        }

        if(candidates[index]<=target){
            storage.push_back(candidates[index]);
            combinationSumFunction(index, target-candidates[index], candidates, storage, ans);
            storage.pop_back();
        }

        combinationSumFunction(index+1, target, candidates, storage, ans);
    }
};