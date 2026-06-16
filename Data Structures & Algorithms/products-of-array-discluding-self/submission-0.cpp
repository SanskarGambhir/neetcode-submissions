class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefixMul = 1;
        int suffixMul = 1;
        vector<int> prefixMultiplication(n,1);
        vector<int> suffixMultiplication(n,1);
        vector<int> result;

        for(int i=1; i<n; i++){
            prefixMul *= nums[i-1];
            prefixMultiplication[i] = prefixMul;

            suffixMul *= nums[n-i];
            suffixMultiplication[n-i-1] = suffixMul;
        }

        for(int i=0; i<n; i++){
            result.push_back(prefixMultiplication[i]*suffixMultiplication[i]);
        }

        return result;
    }
};
