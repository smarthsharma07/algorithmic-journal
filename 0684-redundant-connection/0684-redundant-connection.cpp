class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]); // Path Compression
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        for(int i = 1;i<=edges.size();i++){
            parent[i]=i;
        }
        for(auto& edge: edges){
            int n1 = edge[0];
            int n2 = edge[1];
            int r1 = find(parent,n1);
            int r2 = find(parent,n2);
            if (r1==r2){
                return edge;
            }
            parent[r1] = r2;

        }
        return {};
    }
};