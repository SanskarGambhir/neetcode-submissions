class Solution {
public:
    unordered_map<char, string> letterMapping;

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        int offset = 0;

        for(char i='2'; i<='9'; i++){
            int count = 3;
            if(i=='7' || i=='9') count=4;

            while(count>0){
                letterMapping[i] += ('a'+offset);
                offset++;
                count--;
            }
        }

        vector<string> requiredStrings;
        int n = digits.size();
        for(int i=0; i<n; i++){
            requiredStrings.push_back(letterMapping[digits[i]]);
        }

        string storage = "";
        vector<string> result;
        letterCombinationsFunction(requiredStrings, 0, n, storage, result);

        return result;
    }

    void letterCombinationsFunction(vector<string>& requiredStrings, int index, int n, string& storage, vector<string>& result){
        if(storage.size()==n){
            result.push_back(storage);
            return;
        }

        for(int i=0; i<requiredStrings[index].size(); i++){
            storage += requiredStrings[index][i];
            letterCombinationsFunction(requiredStrings, index+1, n, storage, result);

            storage.pop_back();
        }
    }
};