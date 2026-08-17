class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        int maxCount = INT_MAX;

        for(int i=1; i<strs.size(); i++){
            int count = 0;

            if(strs[i].size() >= n){
                for(int j=0; j<n; j++){
                    if(strs[0][j]==strs[i][j]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                for(int j=0; j<strs[i].size(); j++){
                    if(strs[0][j]==strs[i][j]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
            }

            maxCount = min(count, maxCount);
            if(maxCount==0) return "";
        }

        string firstElement = strs[0];
        string result = firstElement.substr(0, maxCount);

        return result;
    }
};