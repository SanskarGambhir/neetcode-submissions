class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indices;

        for(int i=0; i<n; i++){
            int temp = 0;
            if(indices.empty()){
                indices.push(i);
            }
            else{
                while(!indices.empty() && temperatures[indices.top()]<temperatures[i]){
                    result[indices.top()] = i-indices.top();
                    indices.pop();
                }
                indices.push(i);
            }
        }

        return result;
    }
};
