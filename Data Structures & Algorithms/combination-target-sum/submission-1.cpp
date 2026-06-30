class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> storage;
        vector<vector<int>> result;
        combinationSumFinction(0, target, nums, storage, result);
        return result;
    }

    void combinationSumFinction(int index, int target, vector<int>& nums, vector<int>& storage, vector<vector<int>>& result){
        if(index==nums.size()){
            if(target==0){
                result.push_back(storage);
            }
            return;
        }

        if(nums[index]<=target){
            storage.push_back(nums[index]);
            combinationSumFinction(index, target-nums[index], nums, storage, result);
            storage.pop_back();
        }

        combinationSumFinction(index+1, target, nums, storage, result);
    }
};
