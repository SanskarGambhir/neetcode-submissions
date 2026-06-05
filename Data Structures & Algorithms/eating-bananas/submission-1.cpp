class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = 0;

        while(left <= right){
            int mid = (left+right)/2;
            int totalhours = 0;

            for(int i=0; i<n; i++){
                if(piles[i] % mid != 0){
                    totalhours += (piles[i]/mid)+1;
                }
                else{
                    totalhours += (piles[i]/mid);
                }
            }

            if(totalhours <= h){
                k = mid;
                right = mid-1;
            }
            else if(totalhours > h){
                left = mid+1;
            }
        }

        return k;
    }
};
