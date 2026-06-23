class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<int, int> freq;
        int totalTime = 0;

        for(auto task:tasks){
            freq[task]++;
        }

        for(auto task:freq){
            pq.push(task.second);
        }

        while(!pq.empty()){
            vector<int> temp;
            int currentTime = 0;

            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();

                    freq--;
                    currentTime++;

                    if(freq>0){
                        temp.push_back(freq);
                    }
                }
            }

            for(auto remainingFreq:temp){
                pq.push(remainingFreq);
            }

            if(pq.empty()){
                totalTime += currentTime; 
            }
            else{
                totalTime += n+1;
            }
        }

        return totalTime;
    }
};