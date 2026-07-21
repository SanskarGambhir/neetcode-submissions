class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> highestTrack;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            highestTrack.push({nums[i], i});

            while(!highestTrack.empty() && highestTrack.top().second <= i-k){
                highestTrack.pop();
            }

            if(i >= k-1){
                result.push_back(highestTrack.top().first);
            }
        }

        return result;
    }
};