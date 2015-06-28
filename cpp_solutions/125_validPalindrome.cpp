class Solution {
public:

    bool isPalindrome(string s) {
        if (s.length() == 0){
            return true;
        }
        int i = 0;
        int j = s.length() - 1;

        while(i < j){ // i <= j is OK
            while(!isalnum(s[i]) && i < s.length()){
                i++;
            }
            while(!isalnum(s[j]) && j >= 0){
                j--;
            }
            if ( i >= j){// i > j is also OK
                return true;
            }
            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
