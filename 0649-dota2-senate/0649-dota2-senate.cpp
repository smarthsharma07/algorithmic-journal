class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r;
        queue<int> d;
        for (int i = 0; i<n;i++){
            if(senate[i]=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        while (!r.empty() && !d.empty()){
            int rin = r.front();
            r.pop();
            int din = d.front();
            d.pop();
            if(rin<din){
                r.push(rin+n);
            }
            else{
                d.push(din+n);
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};