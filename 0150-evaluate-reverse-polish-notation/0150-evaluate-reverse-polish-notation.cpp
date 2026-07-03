class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (string tk : tokens){
            if(tk == "+" || tk == "-" || tk == "*" || tk == "/"){
                int b  = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tk=="+"){
                    st.push(a+b);
                }
                else if (tk=="-"){
                    st.push(a-b);
                }
                else if (tk=="*"){
                    st.push(a*b);
                }
                else {
                    st.push(a/b);
                }

            }
            else{
                st.push(stoi(tk));
            }

        }
        return st.top();
    }
};