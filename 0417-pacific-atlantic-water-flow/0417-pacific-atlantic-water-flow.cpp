class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis)
    {       vis[r][c] = true;
        for(auto &d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr<0 || nc<0 || nr>=m || nc>=n)
                continue;
            if(vis[nr][nc])
                continue;
            if(heights[nr][nc] < heights[r][c])
                continue;
            dfs(nr,nc,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));
        for(int j=0;j<n;j++)
            if(!pacific[0][j])
                dfs(0,j,heights,pacific);
        for(int i=0;i<m;i++)
            if(!pacific[i][0])
                dfs(i,0,heights,pacific);
        for(int j=0;j<n;j++)
            if(!atlantic[m-1][j])
                dfs(m-1,j,heights,atlantic);
        for(int i=0;i<m;i++)
            if(!atlantic[i][n-1])
                dfs(i,n-1,heights,atlantic);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};