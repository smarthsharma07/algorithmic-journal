class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    string word;
    TrieNode(){
        isEnd = false;
        word = "";
        for(int i = 0; i<26;i++){
            child[i]=nullptr;
        }
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
        node->word = word;     
    }
    vector<string> ans;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
     void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if(c == '#') return;
        if(node->child[c-'a'] == nullptr)
            return;
        node = node->child[c-'a'];
        if(node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;   
        }
        board[i][j] = '#';
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size())
                dfs(board,ni,nj,node);
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string &w: words){
            insert(w);
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,root);
        return ans;
    }
};