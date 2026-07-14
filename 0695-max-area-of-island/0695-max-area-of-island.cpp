class Solution {
public:
    int bfs(vector<vector<int>>& grid,int row, int col){
         int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        grid[row][col] = 0;
        int area=0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            area++;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }    
        }
        return area; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxarea=0;
        for (int i = 0 ; i<m;i++){
            for (int j = 0; j<n;j++){
                if (grid[i][j] == 1) {
                    maxarea = max(maxarea, bfs(grid, i, j));
                }
            }
        }
        return maxarea;
    }
};