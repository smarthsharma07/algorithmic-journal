class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string> ans;
        int n = words.size();
        int i=0;
        while (i<n){
            int j = i;
            int letters = 0;
            while(j<n && letters + words[j].size() + (j - i) <= maxWidth){
                letters+=words[j].size();
                j++;
            }
            int gaps = j-i-1;
            string line;
            if (j==n || gaps==0){
                for (int k=i;k<j;k++){
                    line+=words[k];
                    if (k!=j-1){
                        line+=' ';
                    }
                }
                while(line.size()<maxWidth){
                    line+=' ';
                }
            }
            else {
                int totalSpaces = maxWidth - letters;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                for (int k=i;k<j;k++){
                    line+=words[k];
                    if (k!=j-1){
                        line.append(evenSpaces,' ');
                        if (extraSpaces>0){
                            line+=' ';
                            extraSpaces--;
                        }
                    }
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};