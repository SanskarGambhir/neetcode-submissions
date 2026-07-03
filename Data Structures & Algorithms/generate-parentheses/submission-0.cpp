class Solution {
public:
    unordered_map<string, int> present;

    vector<string> generateParenthesis(int n) {
        string s = "";
        string tempString = "";
        vector<string> result;
        vector<bool> alreadyUsed(2*n, false);
        
        for(int i=0; i<n; i++){
            s += "()";
        }
        sort(s.begin(), s.end());

        generateParenthesisFunction(s, alreadyUsed, tempString, result);
        return result;
    }

    void generateParenthesisFunction(string& s, vector<bool>& alreadyUsed, string& tempString, vector<string>& result){
        if(tempString.size()==s.size()){
            if(present.find(tempString)!=present.end()){
                return;
            }

            present[tempString]++;
            bool valid = validParanthesis(tempString);

            if(valid){
                result.push_back(tempString);
            }
            return;
        }

        for(int i=0; i<s.size(); i++){
            if(alreadyUsed[i]==true){
                continue;
            }

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

    bool validParanthesis(string tempString){
        stack<char> st;

        for(int i=0; i<tempString.size(); i++){
            if(tempString[i] == '('){
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