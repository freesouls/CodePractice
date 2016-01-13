class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++){
            dic[i] = NULL;
        }
    }
    
    void addChild(int ch, TrieNode* node){
        dic[ch] = node;
    }

public:
    //char c;
    bool isWord;
    TrieNode* dic[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        root->isWord = true;
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size() == 0) return;
        TrieNode* node = root;
        TrieNode* current = NULL;
        int i = 0;
        for (; i < s.size(); i++){
            current = node->dic[s[i] - 'a'];
            if (!current){
                break;
            }
            node = current;
        }
        
        for (; i < s.size(); i++){
            TrieNode* tmp = new TrieNode();
            node->addChild(s[i] - 'a', tmp);
            node = tmp;
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if (key.size() == 0) return true;
        TrieNode* node = root;
        for (int i = 0; i < key.size(); i++){
            node = node->dic[key[i] - 'a'];
            if (!node){
                return false;
            }
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.size() == 0) return true;
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++){
            node = node->dic[prefix[i] - 'a'];
            if (!node){
                return false;
            }
        }
        return true;
    }
    
    int hasPrefix(string& prefix) {
        if (prefix.size() == 0) return 2; // 2 means the prefix is a word
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++){
            node = node->dic[prefix[i] - 'a'];
            if (!node){
                return 0; // 0 means does not exist
            }
        }
        if (node->isWord) {
            return 2; // 2 means the prefix is a word
        }
        else{
            return 1; // 1 means the prefix is not a word
        }
    }
    
public:
    TrieNode* root;
};

class Solution {
public:
    Trie trie;
    vector<string> res;
    int m = 0;
    int n = 0;
    int len = 0;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        if (words.size() == 0 || board.size() == 0){
            return res;
        }
        m = board.size();
        n = board[0].size();
        len = words.size();
        if (n){
            trie = *(new Trie());
            for (int i = 0; i < len; i++){
                trie.insert(words[i]);
            }
            string str = "";
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    searchWords(board, i, j, str, trie.root);
                }
            }
        }
        
        return res;
    }
    
    void searchWords(vector<vector<char>>& board, int i, int j, string str, TrieNode* node){
        node = node->dic[board[i][j] - 'a'];
        if (node){
            str.push_back(board[i][j]);
            if (node->isWord && std::find(res.begin(), res.end(), str) == res.end()) {
                res.push_back(str);
            }
            char tmp = board[i][j];
            board[i][j] = 0;
            if (i > 0 && board[i-1][j]) searchWords(board, i-1, j, str, node);
            if (i < m - 1 && board[i+1][j]) searchWords(board, i+1, j, str, node);
            if (j > 0 && board[i][j-1]) searchWords(board, i, j-1, str, node);
            if (j < n - 1 && board[i][j+1]) searchWords(board, i, j+1, str, node);
            board[i][j] = tmp;
        }
    }
};

/* version 2, need m*n space
class Solution {
public:
    Trie trie;
    vector<vector<int> > visited;
    vector<string> res;
    int m = 0;
    int n = 0;
    int len = 0;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        if (words.size() == 0 || board.size() == 0){
            return res;
        }
        m = board.size();
        n = board[0].size();
        len = words.size();
        if (n){
            visited.clear();
            vector<int> tmp(n, 0);
            for (int i = 0; i < m; i++){
                visited.push_back(tmp);
            }
            trie = *(new Trie());
            for (int i = 0; i < len; i++){
                trie.insert(words[i]);
            }
            string str = "";
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    searchWords(board, i, j, str);
                }
            }
        }
        return res;
    }
    
    void searchWords(vector<vector<char>>& board, int i, int j, string str){
        str.push_back(board[i][j]);
        int f = trie.hasPrefix(str);
        if (f == 0) return;
        if (f == 2 && std::find(res.begin(), res.end(), str) == res.end()) {
            res.push_back(str);
        }
        visited[i][j] = 1;
        if (i > 0 && !visited[i-1][j]) searchWords(board, i-1, j, str);
        if (i < m - 1 && !visited[i+1][j]) searchWords(board, i+1, j, str);
        if (j > 0 && !visited[i][j-1]) searchWords(board, i, j-1, str);
        if (j < n - 1 && !visited[i][j+1]) searchWords(board, i, j+1, str);
        visited[i][j] = 0;
    }
};
*/