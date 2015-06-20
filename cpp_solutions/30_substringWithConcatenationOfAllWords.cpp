//TODO: optimization
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() == 0 || words.size() == 0){
            return res;
        }
        int n = words.size();
        int len = words[0].length();
        int all = n*len;
        if (s.length() < all) {
            return res;
        }
        
        unordered_map<string, int> count;
        for(int i = 0; i < words.size(); i++){
            if (count.find(words[i]) == count.end()){
                count[words[i]] = 1;
            }
            else{
                count[words[i]]++;
            }
        }
        
        for (int i = 0; i <= s.length() - all; i++){
            unordered_map<string, int> dic(count);
            
            int j = i;
            int end = j + all;
            while(j < end){
                string tmp = s.substr(j, len);
                if (dic.find(tmp) != dic.end()){
                    dic[tmp]--;
                    if (dic[tmp] == 0){
                        dic.erase(tmp);
                    }
                }
                else{
                    break;
                }
                j += len;
            }
            if (dic.size() == 0){
                res.push_back(i);
            }
        }
        
        return res;
    }
};