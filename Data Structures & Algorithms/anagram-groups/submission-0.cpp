class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> frequency;

        for(string p:strs){
            string temp = p;
            sort(temp.begin(), temp.end());
            frequency[temp].push_back(p);
        }

        vector<vector<string>> result;
        
        for(auto s:frequency){
            result.push_back(s.second);
        }
        return result;
    }
};