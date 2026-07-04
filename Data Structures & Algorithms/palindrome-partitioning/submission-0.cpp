class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> storage;
        vector<vector<string>> result;

        partitionFunction(0, s, storage, result);
        return result;
    }

    void partitionFunction(int index, string& s, vector<string>& storage, vector<vector<string>>& result){
        if(index==s.size()){
            result.push_back(storage);
            return;
        }

        string tempString = "";

        for(int i=index; i<s.size(); i++){
            tempString += s[i];

            if(isPalindrome(tempString)){
                storage.push_back(tempString);
                partitionFunction(i+1, s, storage, result);
                storage.pop_back();
            }
        }
    }

    bool isPalindrome(string tempString){
        int left=0, right=tempString.size()-1;

        while(left<=right){
            if(tempString[left]!=tempString[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};