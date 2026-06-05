class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;

        for(i=0; i<m; i++){
            if(matrix[i][n-1] >= target){
                break;
            }
        }
        if(i == m){
            return false;
        }

        int left=0;
        int right=n-1;
        
        while(left<=right){
            int mid = (left+right)/2;

            if(matrix[i][mid] == target){
                return true;
            }
            else if(matrix[i][mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return false;
    }
};
