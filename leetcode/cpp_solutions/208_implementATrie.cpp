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

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");