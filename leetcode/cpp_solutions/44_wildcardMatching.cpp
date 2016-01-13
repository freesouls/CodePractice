class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }


    bool isMatch(const char* s, const char* p){
        bool star = false;
        const char* str, *ptr;
        for(str = s, ptr = p; *str != '\0'; str++, ptr++){
            switch (*ptr){
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while(*p == '*'){
                        p++;
                    }
                    if (*p == '\0'){
                        return true;
                    }
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                    if (*str != *ptr){
                        if (!star){
                            return false;
                        }
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
            }
        }
        while(*ptr == '*'){
            ptr++;
        }

        return '\0' == *ptr;
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p){
        if (*p == '\0') return *s == '\0';
        if (*(p) != '*'){
            return (*s == *p || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        while(*(p+1) == '*'){
            p++;
        }
        while(*s != '\0'){
            if (isMatch(s, p+1)) return true;
            s++;
        }
        return false;
    }
};
*/
