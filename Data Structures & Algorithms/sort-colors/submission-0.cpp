class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int j=0; j<n; j++){
            if(nums[j] == 0){
                count0++;
            }
            else if(nums[j] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }

        while(count0>0){
            nums[i] = 0;
            count0--;
            i++;
        }
        while(count1>0){
            nums[i] = 1;
            count1--;
            i++;
        }
        while(count2>0){
            nums[i] = 2;
            count2--;
            i++;
        }
    }
};