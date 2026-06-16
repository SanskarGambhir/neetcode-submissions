class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c:s){
            if(isalnum(c)){
                str += tolower(c);
            }
        }
        int len = str.length();
        for(int i=0; i<len/2; i++){
            if(str[i] != str[len-i-1]){
                return false;
            }
        }
        return true;
    }
};