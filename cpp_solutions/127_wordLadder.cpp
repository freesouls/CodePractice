// need speed optimization
// change visited to map<string, int> does not improve speed
// TODO: every time erase the element in wordDict may be good, but destory wordDict
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        
        if (wordDict.size() == 0 || beginWord.size() == 0 || endWord.size() == 0){
            return 0;
        }
        
        unordered_set<string> visited;
        vector<bool> visited(wordDict.size(), false);
        queue<string> q;
        int cur = 0;
        int last = 1;
        int res = 1;
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()){
            string next = q.front();
            q.pop();
            last--;
            for (int i = 0; i < next.size(); i++){
                //string next = tmp;
                for (char ch = 'a'; ch <= 'z'; ch++){
                    if (next[i] != ch){
                        char tmp = next[i];
                        next[i] = ch;
                        if (next ==  endWord){
                            return res + 1;
                        }
                        
                        if (wordDict.find(next) != wordDict.end() 
                        && visited.find(next) == visited.end()){
                            visited.insert(next);
                            q.push(next);
                            cur++;
                        }
                        next[i] = tmp;
                    }
                }
            }
            
            if (last == 0){
                last = cur;
                res++;
                cur = 0;
            }
        }
        return 0;
    }
};