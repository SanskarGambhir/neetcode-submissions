class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Find max k times
        for (int i = 0; i < k; i++) {
            int maxFreq = 0;
            int maxNum = 0;

            for (auto& c : freq) {
                if (c.second > maxFreq) {
                    maxFreq = c.second;
                    maxNum = c.first;
                }
            }

            result.push_back(maxNum);
            freq.erase(maxNum);
        }

        return result;
    }
};