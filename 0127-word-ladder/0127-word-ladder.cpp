class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int L = beginWord.length();

        // Generic word -> list of words
        unordered_map<string, vector<string>> allComboDict;

        for (const string &word : wordList) {
            for (int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1);
                allComboDict[newWord].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_map<string, bool> visited;
        visited[beginWord] = true;

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            for (int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1);
                for (const string &adjWord : allComboDict[newWord]) {
                    if (adjWord == endWord)
                        return level + 1;
                    if (!visited[adjWord]) {
                        visited[adjWord] = true;
                        q.push({adjWord, level + 1});
                    }
                }
                allComboDict[newWord].clear();
            }
        }
        return 0;
    }
};