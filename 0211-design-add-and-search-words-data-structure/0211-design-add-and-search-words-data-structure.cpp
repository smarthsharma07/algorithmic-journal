class WordDictionary {
private:
    struct TrieNode{
         TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }        
    };
    TrieNode* root;
    bool dfs(string &word, int idx, TrieNode* node) {
        if (idx == word.size())
            return node->isEnd;
        char c = word[idx];
        if (c != '.') {
            int ind = c - 'a';
            if (node->child[ind] == nullptr)
                return false;
            return dfs(word, idx + 1, node->child[ind]);
        }
        for (int i = 0; i < 26; i++) {
            if (node->child[i] && dfs(word, idx + 1, node->child[i]))
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */