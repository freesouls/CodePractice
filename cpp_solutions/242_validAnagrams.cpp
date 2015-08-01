class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        vector<int> count(128, 0);
        for (int i = 0; i < s.length(); i++){
            count[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++){
            count[t[i]]--;
            if (count[t[i]] < 0){
                return false;
            }
        }

        for (int i = 0; i < count.size(); i++){
            if (count[i] > 0){
                return false;
            }
        }

        return true;
    }

    bool isAnagram1(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t){
            return true;
        }
        else{
            return false;
        }
    }
};
