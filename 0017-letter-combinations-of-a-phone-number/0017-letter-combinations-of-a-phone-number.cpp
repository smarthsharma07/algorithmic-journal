class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    void solve(int idx, string &curr, string &digits) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string letters = mp[digits[idx]];
        for (char ch : letters) {
            curr.push_back(ch);          
            solve(idx + 1, curr, digits); 
            curr.pop_back();             
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};
        string curr = "";
        solve(0, curr, digits);
        return ans;
    }
};