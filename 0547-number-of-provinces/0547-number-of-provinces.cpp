class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int start){
        queue<int>q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int city = q.front();
            q.pop();
             for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
                if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }    
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int prov = 0;
        for(int i = 0; i<n;i++){
            if(!visited[i]){
                bfs(isConnected,visited,i);
                prov++;
            }
        }
        return prov;
    }
};