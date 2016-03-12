class Solution {
public:
    bool isPalindrome(string s){
        int n=s.length();
        for(int i=0, j=n-1; i<j; i++, j--){
            if(s[i] != s[j])return false;
        }
        return true;
    }

    //return all the possible string that could be a pair of s
    void helper(string s, vector<string>& left, vector<string>& right){
        int len=s.length();

        for(int i=0; i<len; i++){// it should not be i<=len, because the word which is already palindrome need to be consider alone
            //add to the word's left side
            if(isPalindrome(s.substr(0,i))){
                string tmp=s.substr(i);
                reverse(tmp.begin(), tmp.end());
                left.push_back(tmp);
            }
            //add to the word's right side and avoid to compute the condition i==0, because words like "abc" and "cba" can generate duplicates
            if(isPalindrome(s.substr(len-i)) && i!=0){
                string tmp=s.substr(0,len-i);
                reverse(tmp.begin(), tmp.end());
                right.push_back(tmp);
            }
        }

    }

    vector<vector<int>> palindromePairs(vector<string>& words){
        vector<vector<int>> res;
        unordered_map<string, int> um;
        vector<int> v(2, 0);
        int n=words.size(), index_empty=-1;
        for(int i=0; i<n; i++)um[words[i]]=i;
        if(um.find("")!=um.end())index_empty=um[""];

        for(int i=0; i<n; i++){
            if(words[i]=="")continue;
            //deal with the word which itself is a palindrome
            if(isPalindrome(words[i]) && index_empty!=-1){
                v[0]=index_empty; v[1]=i; res.push_back(v);
                v[1]=index_empty; v[0]=i; res.push_back(v);
            }
            vector<string> left, right;
            helper(words[i], left, right);
            for(int j=0; j<left.size(); j++){
                if(um.find(left[j])!=um.end()){
                    v[0]=um[left[j]]; v[1]=i;
                    if(v[0]!=v[1]) res.push_back(v);//check v[0]==v[1]
                }
            }
            for(int j=0; j<right.size(); j++){
                if(um.find(right[j])!=um.end()){
                    v[1]=um[right[j]]; v[0]=i;
                    if(v[0]!=v[1]) res.push_back(v);
                }
            }
        }
        return res;
    }
};

// TLE
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;

        for (int i = 0; i < words.size()-1; i++) {
            for (int j = i+1; j < words.size(); j++) {
                int tmp = check(words[i], words[j]);
                if (tmp == 0) {
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    res.push_back(a);
                }

                if (tmp == 1) {
                    vector<int> a;
                    a.push_back(j);
                    a.push_back(i);
                    res.push_back(a);
                }

                if (tmp == 2) {
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    res.push_back(a);
                    a.clear();
                    a.push_back(j);
                    a.push_back(i);
                    res.push_back(a);
                }
            }
        }
        return res;
    }

    int check(string& word1, string& word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        if(n1 == n2) {
            // int n = word1.length();
            for (int i = 0; i < n1; i++) {
                if (word1[i] != word2[n1-1-i]) {
                    return -1;
                }
            }
            return 2;
        }

        bool flag1;
        bool flag2;
        if (n1 < n2) {
            flag1 = check2(word1, word2);
            flag2 = check3(word2, word1);
        }
        else{
            flag1 = check3(word1, word2);
            flag2 = check2(word2, word1);
        }

        if (flag1) {
            return flag2? 2: 0;
        }
        else{
            return flag2? 1: -1;
        }

    }

    bool check2(string& word1, string& word2) { // word1.len < word2.len
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0, j = n2-1;
        while(i < n1) {
            if (word1[i] != word2[j]) {
                return false;
            }
            i++;
            j--;
        }
        i = 0;
        while( i < j) {
            if (word2[i] != word2[j]) {
                false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool check3(string& word1, string& word2) { // word1.len > word2.len
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0, j = n2-1;
        while(j >= 0) {
            if (word1[i] != word2[j]) {
                return false;
            }
            i++;
            j--;
        }
        j = n1-1;
        while( i < j) {
            if (word1[i] != word1[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
