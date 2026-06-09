class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int num1 = 0;
        int num2 = 0;
        stack<int> numbers;

        for(int i=0; i<n; i++){
            if(isInteger(tokens[i])){
                numbers.push(stoi(tokens[i]));
            }
            else{
                num1 = numbers.top();
                numbers.pop();
                num2 = numbers.top();
                numbers.pop();

                int result = 0;

                if(tokens[i] == "+"){
                    result = num2 + num1;
                }
                else if(tokens[i] == "-"){
                    result = num2 - num1;
                }
                else if(tokens[i] == "*"){
                    result = num2 * num1;
                }
                else{
                    result = num2 / num1;
                }

                numbers.push(result);
            }
        }

        return numbers.top();
    }

    bool isInteger(string s) {
        int start = 0;

        if (s[0]=='-') {
            if (s.size() == 1) return false;
            start = 1;
        }

        for (int i=start; i<s.size(); i++) {
            if (!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }
};
