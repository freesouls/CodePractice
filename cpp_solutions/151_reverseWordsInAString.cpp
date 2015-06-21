// TODO : C , O(1) constant space
class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int i = s.length() - 1;
        while(1){
            
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            if (i < 0){
                break;
            }
            int end = i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            
            if (res.size() == 0){
                res = s.substr(i+1, end - i);
            }
            else{
                res += " " + s.substr(i+1, end - i);
            }
            if (i < 0){
                break;
            }
        }
        s = res;
    }
};