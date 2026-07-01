class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> storage;
        vector<vector<int>> result;

        combinationSum2Function(0, target, candidates, storage, result);

        return result;
    }

    void combinationSum2Function(int index, int target, vector<int>& candidates, vector<int>& storage, vector<vector<int>>& result){
        if(target==0){
            result.push_back(storage);
            return;
        }

        if(index==candidates.size()){
            return;
        }

        if(candidates[index]<=target){
            storage.push_back(candidates[index]);
            combinationSum2Function(index+1, target-candidates[index], candidates, storage, result);
            storage.pop_back();
        }

        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }

        combinationSum2Function(index+1, target, candidates, storage, result);
    }
};