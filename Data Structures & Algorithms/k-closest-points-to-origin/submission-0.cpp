class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > distance;

        for(auto coordinates:points){
            int x1 = coordinates[0];
            int y1 = coordinates[1];

            int squareRoot = (x1)*(x1) + (y1)*(y1);
            distance.push({squareRoot, coordinates});
        }

        vector<vector<int>> result;

        while(!distance.empty() && result.size()<k){
            result.push_back(distance.top().second);
            distance.pop();
        }

        return result;
    }
};