class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int left = 0;
        int right;
        unordered_map<char, int> freq;

        for(right=0; right<n; right++){
            freq[s[right]]++;

            if(freq[s[right]]>1){
                while(freq[s[right]]>1){
                    freq[s[left]]--;

                    if(freq[s[left]] == 0){
                        freq.erase(s[left]);
                    }

                    left++;
                }
                
            }

            maxLength = max(right-left+1, maxLength);
        }

        return maxLength;
    }
};
