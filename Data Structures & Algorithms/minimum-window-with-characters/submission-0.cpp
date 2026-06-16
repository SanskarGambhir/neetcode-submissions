class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;
        int left=0, right=0;
        int matched = 0;
        int minLen=INT_MAX, start = 0;
        string result = "";

        for(auto c:t){
            tFreq[c]++;
        }
        int requiredToBeMatched = tFreq.size();

        while(right<n1){
            sFreq[s[right]]++;

            if(tFreq.find(s[right])!=tFreq.end() && sFreq[s[right]]==tFreq[s[right]]){
                matched += 1;
            }

            while(left<=right && matched==requiredToBeMatched){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }

                sFreq[s[left]]--;
                if(tFreq.find(s[left])!=tFreq.end() && sFreq[s[left]]<tFreq[s[left]]){
                    matched -= 1;
                }

                left++;
            }

            right++;
        }

        if(minLen!=INT_MAX){
            result = s.substr(start, minLen);
        }        
        return result;
    }
};