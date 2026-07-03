class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> ri;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    ri.insert(i);
                } 
                else {
                    st.pop();
                }
            }
        }
        while (!st.empty()){
            ri.insert(st.top());
            st.pop();
        }
        string ans = "";
        for(int i = 0 ; i<s.size();i++){
            if (ri.find(i)==ri.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};