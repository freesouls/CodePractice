class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
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

        return true;
    }
    // this algorithm can pass the judge
    // but for 'aa', 'bb' return true
    bool anagram(string s, string t) {
        // write your code here
        int l1 = s.size();
        int l2 = t.size();
        if(l2 != l1) {
            return false;
        }
        int s1 = 0, t1 = 0;
        for(int i = 0;i < l1; i++){
            s1 = s1^s[i];
            t1 = t1^t[i];
        }
        if(s1 == t1) {
            return true;
        }
        return false;
    }
};
