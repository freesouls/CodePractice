class TrieNode {
public:
    bool iskey;
    TrieNode *children[26]; 
    TrieNode() {
        iskey = false;
        for(int i=0; i<26; ++i)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); ++i)
        {
            if(node->children[word[i]-'a'] == NULL)
            {
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->iskey = true;
    }

    bool search(string word) {
        return searchWord(word, root, 0);
    }

private:
    TrieNode* root;

    bool searchWord(string &word, TrieNode* node, int p) {
        if(p == word.size())
            return node->iskey;

        if(word[p] == '.') {
            for(int i=0; i<26; ++i)
                if(node->children[i] && searchWord(word, node->children[i], p+1))
                    return true;
            return false;
        }
        else
            return node->children[word[p]-'a'] && searchWord(word, node->children[word[p]-'a'], p+1);
    }
};
