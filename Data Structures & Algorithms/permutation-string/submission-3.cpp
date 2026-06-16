class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char, int> s1Freq;
        unordered_map<char, int> s2Freq;

        for(auto c:s1){
            s1Freq[c]++;
        }

        for(int i=0; i<n2; i++){
            s2Freq[s2[i]]++;

            if(i>=n1){
                s2Freq[s2[i-n1]]--;

                if(s2Freq[s2[i-n1]] == 0){
                    s2Freq.erase(s2[i-n1]);
                }
            }

            if(s2Freq == s1Freq){
                return true;
            }
        }

        return false;
    }
};