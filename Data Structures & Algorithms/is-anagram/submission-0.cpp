class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> frequency;

        for (char c : s){
            frequency[c]++;
        }

        for (char c : t){
            frequency[c]--;
        };

        for (auto &p : frequency) {
            if (p.second != 0) return false;
        }

        return true;
    }
};