class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> storage;
        vector<vector<int>> result;
        combinationSumFunction(0, target, candidates, storage, result);
        return result;
    }

    void combinationSumFunction(int index, int target, vector<int>& candidates, vector<int>& storage, vector<vector<int>>& result){
        if(target==0){
            result.push_back(storage);
            return;
        }

        if(index==candidates.size()){
            return;
        }

        if(candidates[index]<=target){
            storage.push_back(candidates[index]);
            combinationSumFunction(index, target-candidates[index], candidates, storage, result);
            storage.pop_back();
        }

        combinationSumFunction(index+1, target, candidates, storage, result);
    }
};