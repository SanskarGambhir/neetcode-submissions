class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> present;
        
        for(int i=0; i<n; i++){
            int diff = target - nums[i];

            if(present.find(diff) != present.end()){
                return{present[diff], i};
            }

            present[nums[i]] = i;
        }
        return {-1};
    }
};