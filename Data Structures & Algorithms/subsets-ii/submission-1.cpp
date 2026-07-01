class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> storage;
        vector<vector<int>> result;

        subsetsWithDupFunction(0, nums, storage, result);

        return result;
    }

    void subsetsWithDupFunction(int index, vector<int>& nums, vector<int>& storage, vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(storage);
            return;
        }

        storage.push_back(nums[index]);
        subsetsWithDupFunction(index+1, nums, storage, result);
        storage.pop_back();

        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }

        subsetsWithDupFunction(index+1, nums, storage, result);
    }
};