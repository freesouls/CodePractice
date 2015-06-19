class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        //dic.clear();
        isWord = false;
    }
    
    TrieNode(char a){
        c = a;
        //dic.clear();
        isWord = false;
    }
    
    // bool containChar(char a){
    //     return dic.find(a) != dic.end()? true; false;
    // }
    
    inline void addChild(char a, TrieNode* t){
        dic[a] = t;
    }
    
    inline TrieNode* containChar(char a){
        if(dic.find(a) != dic.end()){
            return dic[a];
        }
        else{
            return NULL;
        }
    }
    
public:
    bool isWord;
    char c;
    map<char, TrieNode*> dic;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size() == 0) return;
        TrieNode* node = root;
        TrieNode* current = NULL;
        int i = 0;
        for (; i < s.size(); i++){
            current = node->containChar(s[i]);
            if (current){
                node = current;
            }
            else{
                break;
            }
        }
        
        for (; i < s.size(); i++){
            TrieNode* tmp = new TrieNode(s[i]);
            node->addChild(s[i], tmp);
            node = tmp;
        }
        node->isWord = true;
        
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if (key.size() == 0) return true;

        TrieNode* node = root;
        TrieNode* current = NULL;
        for (int i = 0; i < key.size(); i++){
            current = node->containChar(key[i]);
            if (current){
                node = current;
            }
            else{
                return false;
            }
        }
        return current->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.size() == 0) return true;
        TrieNode* node = root;
        TrieNode* current = NULL;
        for (int i = 0; i < prefix.size(); i++){
            current = node->containChar(prefix[i]);
            if (current){
                node = current;
            }
            else{
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