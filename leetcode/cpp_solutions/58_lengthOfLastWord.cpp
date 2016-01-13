class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool end_is_space = false;
        int i = s.size() - 1;
        while(s[i] == ' ' && i>= 0){
            i--;
        }
        
        while(s[i] != ' ' && i>=0){
            i--;
            len++;
        }
        
        return len;
    }
};