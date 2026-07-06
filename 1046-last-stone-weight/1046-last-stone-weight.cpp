class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for (int stone : stones){
            q.push(stone);
        }
        while(q.size()>1){
            int y = q.top();
            q.pop();
            int z = q.top();
            q.pop();
            if (y!=z){
                q.push(y-z);
            }
        }
        if (q.empty()){
            return 0;
        }
        return q.top();
    }
};