class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> pathVisited;
    bool dfs(int node) {
        visited[node] = true;
        pathVisited[node] = true;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei))
                    return true;
            }
            else if (pathVisited[nei]) {
                return true;        // cycle found
            }
        }
        pathVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i))
                    return false;
            }
        }
        return true;
    }
};