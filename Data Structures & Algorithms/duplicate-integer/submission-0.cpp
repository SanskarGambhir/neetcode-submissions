class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> seen;

        for(int i=0; i<n; i++){
            if(seen.find(nums[i]) != seen.end()){
                return true;
            }

            seen[nums[i]]++;
        }

        return false;
    }
};