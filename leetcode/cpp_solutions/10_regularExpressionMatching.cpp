class Solution {
public:
    bool isMatch(const char* s, const char* p){
        if (*p == '\0') return *s == '\0';
        // if next char is not '*'
        if (*(p+1) != '*'){
            // assert(*p != '*');
            return (*s == *p || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1); 
        }
        // if next char is '*'
        while(*s == *p || (*p == '.' && *s != '\0')){
            if (isMatch(s, p+2)) return true;
            s++;
        }
        // isMatch(aabc, a*ba*c), isMatch(aabc, a*bac)
        return isMatch(s, p+2);
    }
    
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
};