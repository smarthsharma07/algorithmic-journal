class Solution {
public:
    const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> digits;
        vector<int> pos;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='0')
            {
                digits.push_back(s[i]-'0');
                pos.push_back(i);
            }
        }
        int m = digits.size();
        vector<long long> pow10(m+1,1);
        for(int i=1;i<=m;i++)
            pow10[i]=(pow10[i-1]*10)%MOD;

        vector<long long> pref(m+1,0);
        for(int i=0;i<m;i++)
            pref[i+1]=(pref[i]*10+digits[i])%MOD;
        vector<int> digitPref(m+1,0);
        for(int i=0;i<m;i++)
            digitPref[i+1]=digitPref[i]+digits[i];
        vector<int> first(n,-1), last(n,-1);
        int ptr=0;
        for(int i=0;i<n;i++)
        {
            while(ptr<m && pos[ptr]<i)
                ptr++;
            if(ptr<m)
                first[i]=ptr;
        }
        ptr=m-1;
        for(int i=n-1;i>=0;i--)
        {
            while(ptr>=0 && pos[ptr]>i)
                ptr--;
            if(ptr>=0)
                last[i]=ptr;
        }
        vector<int> ans;
        for(auto &q:queries)
        {
            int l=q[0];
            int r=q[1];
            int L=first[l];
            int R=last[r];
            if(L==-1 || R==-1 || L>R)
            {
                ans.push_back(0);
                continue;
            }
            int len=R-L+1;
            long long x=(pref[R+1]-pref[L]*pow10[len])%MOD;
            x=(x+MOD)%MOD;
            long long sum=digitPref[R+1]-digitPref[L];
            ans.push_back((x*sum)%MOD);
        }
        return ans;
    }
};