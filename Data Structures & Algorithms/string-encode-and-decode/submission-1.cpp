class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string result = "";

        for(int i=0; i<n; i++){
            result += to_string(strs[i].size()) + '#' + strs[i];
        }

        return result;
    }
    

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> result;
        int i = 0;
        int j = 0;

        while(i<n){
            string substring = "";
            string subStringSize = "";
            int count = 0;

            while(s[i] != '#'){
                subStringSize += s[i];
                i++;
            }

            int lenOfSubstring = stoi(subStringSize);
            j = i+1;

            while(j<n && count<lenOfSubstring){
                count++;
                substring += s[j];
                j++;
            }

            result.push_back(substring);
            i = j;
        }

        return result;
    }
};
