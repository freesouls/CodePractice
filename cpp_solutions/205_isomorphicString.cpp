class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        
        char map[256];
        bool used[256];
        memset(map, 0, sizeof(char)*256);
        memset(used, false, sizeof(bool)*256);
        for (int i = 0; i < s.length(); i++){
            int a = t[i];
            char tmp = map[t[i]];
            if (tmp == 0){
                if (used[s[i]]) {
                    return false;
                }
                map[t[i]] = s[i];
                used[s[i]] = true;
            }
            else{
                if(tmp != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
