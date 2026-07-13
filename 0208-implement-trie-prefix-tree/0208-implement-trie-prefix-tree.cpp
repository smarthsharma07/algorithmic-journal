class Trie {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    TrieNode* searchPrefix(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
                return nullptr;
            node = node->child[idx];
        }
        return node;
    }
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node!=nullptr && node->isEnd;
    }
        
    bool startsWith(string prefix) {
        return searchPrefix(prefix) !=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */