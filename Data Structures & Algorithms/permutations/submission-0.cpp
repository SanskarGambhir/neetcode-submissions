class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> storage;
        vector<vector<int>> result;
        vector<bool> alreadyUsed(nums.size(), false);
        permuteFunction(nums, alreadyUsed, storage, result);
        return result;
    }

    void permuteFunction(vector<int>& nums, vector<bool>& alreadyUsed, vector<int>& storage, vector<vector<int>>& result){
        if(storage.size()==nums.size()){
            result.push_back(storage);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(alreadyUsed[i]==true){
                continue;
            }

            storage.push_back(nums[i]);
            alreadyUsed[i] = true;
            permuteFunction(nums, alreadyUsed, storage, result);
            storage.pop_back();

            alreadyUsed[i] = false;
        }
    }
};