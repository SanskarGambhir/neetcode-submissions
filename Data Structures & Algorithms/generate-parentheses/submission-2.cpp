class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<bool> alreadyUsed(2*n, false);
        string s = "";
        string tempString = "";
        int count = n;

        while(count>0){
            s += '(';
            count--;
        }
        count = n;
        while(count>0){
            s += ')';
            count--;
        }

        generateParenthesisFunction(s, alreadyUsed, tempString, result);
        return result;
    }

    void generateParenthesisFunction(string& s, vector<bool>& alreadyUsed, string& tempString, vector<string>& result){
        if(tempString.size() == s.size()){
            if(isValidParanthesis(tempString)){
                result.push_back(tempString);
            }
            return;
        }

        for(int i=0; i<s.size(); i++){
            if(alreadyUsed[i]) continue;

            if(i>0 && s[i]==s[i-1] && !alreadyUsed[i-1]){
                continue;
            }

            tempString += s[i];
            alreadyUsed[i] = true;
            generateParenthesisFunction(s, alreadyUsed, tempString, result);

            tempString.pop_back();
            alreadyUsed[i] = false;
        }
    }

    bool isValidParanthesis(string tempString){
        stack<char> st;

        for(int i=0; i<tempString.size(); i++){
            if(tempString[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }

        if(!st.empty()){
            return false;
        }

        return true;
    }
};