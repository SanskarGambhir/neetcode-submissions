class Solution {
   public:
    bool isValid(string s){
        int n = s.size();
        stack<char> parentheses;

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                parentheses.push(s[i]);
            } 
            else{
                if (parentheses.empty()) {
                    return false;
                }
                else if((s[i] == ')' && parentheses.top() == '(') ||
                        (s[i] == '}' && parentheses.top() == '{') ||
                        (s[i] == ']' && parentheses.top() == '[')){
                    parentheses.pop();
                } 
                else{
                    return false;
                }                  
            }
        }

        if(parentheses.empty()){
            return true;
        }

        return false;
    }
};
