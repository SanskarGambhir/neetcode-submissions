class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> storage;
        vector<vector<int>> result;
        subsetsFunction(0, nums, storage, result);
        return result;
    }

    void subsetsFunction(int index, vector<int>& nums, vector<int>& storage, vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(storage);
            return;
        }
        
        storage.push_back(nums[index]);
        subsetsFunction(index+1, nums, storage, result);
        storage.pop_back();

        subsetsFunction(index+1, nums, storage, result);
    }
};