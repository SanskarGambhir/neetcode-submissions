class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> allStones(stones.begin(), stones.end());

        while(allStones.size()>1){
            int stone1 = allStones.top();
            allStones.pop();
            int stone2 = allStones.top();
            allStones.pop();

            if(stone1==stone2){
                continue;
            }
            allStones.push(stone1-stone2);
        }

        if(allStones.empty()){
            return 0;
        }

        return allStones.top();
    }
};