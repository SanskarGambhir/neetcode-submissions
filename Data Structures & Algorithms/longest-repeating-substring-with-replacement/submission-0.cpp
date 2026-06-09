class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLength = 0;
        int maxFreq = 0;
        int left = 0;
        int right = 0;
        vector<int> freq(26,0);

        for(int right=0; right<n; right++){
            freq[s[right]-'A']++;

            maxFreq = max(maxFreq, freq[s[right]-'A']);

            if(k < (right-left+1)-maxFreq){
                while(k < (right-left+1)-maxFreq){
                    freq[s[left]-'A']--;
                    left++;
                }
            }

            maxLength = max(maxLength, right-left+1);
        }

        return maxLength;
    }
};
