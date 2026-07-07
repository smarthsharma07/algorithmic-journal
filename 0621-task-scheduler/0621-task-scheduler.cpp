class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for (char c : tasks){
            freq[c]++;
        }
        priority_queue<int>q;
        for(auto &it : freq){
            q.push(it.second);
        }
        int time = 0;
        while(!q.empty()){
            vector<int>temp;
            for (int i =0; i<n+1;i++){
                if (!q.empty()){
                    temp.push_back(q.top());
                    q.pop();
                }
            }
            for (int freq : temp){
                freq--;
                if (freq>0){
                    q.push(freq);
                }
            }
            if (q.empty()){
                time+=temp.size();
            }
            else{
                time+= n+1;
            }
        }
        return time;
    }
};