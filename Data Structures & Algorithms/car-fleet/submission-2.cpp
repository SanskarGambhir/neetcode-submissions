class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<int> positionStack;
        unordered_map<int, float> timeRequired;

        for(int i=0; i<n; i++){
            float time = (float)(target-position[i]) / speed[i];
            timeRequired[position[i]] = time;
        }

        sort(position.begin(), position.end());

        for(int i=n-1; i>=0; i--){
            if(positionStack.empty()){
                positionStack.push(position[i]);
            }
            else{
                if(timeRequired[positionStack.top()] < timeRequired[position[i]]){
                    positionStack.push(position[i]);
                }
            }
        }

        return positionStack.size();
    }
};
