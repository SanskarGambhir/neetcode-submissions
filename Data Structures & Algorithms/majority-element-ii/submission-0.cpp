class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>freq;
        vector<int> result;

        for(auto num:nums){
            freq[num]++;

            if(freq[num]==(n/3)+1){
                result.push_back(num);
            }
        }

        return result;
    }
};