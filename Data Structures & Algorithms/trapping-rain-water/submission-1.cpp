class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int leftMaxElement = 0;
        int rightMaxElement = 0;
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for(int i=1; i<n; i++){
            leftMaxElement = max(height[i-1], leftMaxElement);
            leftMax[i] = leftMaxElement;
        }

        for(int i=n-2; i>=0; i--){
            rightMaxElement = max(height[i+1], rightMaxElement);
            rightMax[i] = rightMaxElement;
        }

        for(int i=0; i<n; i++){
            int minHeight = min(leftMax[i], rightMax[i]);

            if(height[i] < minHeight){
                maxWater += minHeight - height[i];
            }
        }

        return maxWater;
    }
};
