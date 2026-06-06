class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char, int> freqS1;
        unordered_map<char, int> freqS2;

        for(auto c:s1){
            freqS1[c]++;
        }

        for(int i=0; i<n1; i++){
            freqS2[s2[i]]++;
        }
        if(freqS1 == freqS2){
            return true;
        }
        else{
            for(int i=n1; i<n2; i++){
                freqS2[s2[i]]++;

                freqS2[s2[i-n1]]--;

                if(freqS2[s2[i-n1]] == 0) {
                    freqS2.erase(s2[i-n1]);
                }
                if(freqS1 == freqS2){
                    return true;
                }
            }
        }

        return false;
    }
};
