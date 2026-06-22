class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kLargest;

        for(auto x:nums){
            if(kLargest.size()<k){
                kLargest.push(x);
            }
            else if(x>kLargest.top()){
                kLargest.pop();
                kLargest.push(x);
            }
        }

        return kLargest.top();
    }   
};