class Solution {
public:
    int checkpalindrome(string s, int left, int right){
        int L= left, R=right;
        while (L>=0 && R<s.length() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    string longestPalindrome(string s) {
        if (s.empty() || s.length()<1){
            return "";
        }
        int left=0,right=0;
        for (int i=0;i<s.length();i++){
            int len1= checkpalindrome(s,i,i);
            int len2= checkpalindrome(s,i,i+1);
            int len = max(len1,len2);
            if(len>right-left){
                left=i-(len-1)/2;
                right=i+len/2;
            }
        }
        return s.substr(left,right-left+1);
    }
};