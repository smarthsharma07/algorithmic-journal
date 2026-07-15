class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid.size()==0){
            return -1;
        }
        int n = grid.size();
        int m = grid[0].size();
        int freshC = 0;
        queue<vector<int>> rottenorg;
        for (int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    freshC++;
                }
                else if (grid[i][j]==2){
                    rottenorg.push({i,j});
                }
            }
        }
        if(freshC == 0){
            return 0;
        }
        int min = 0;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!rottenorg.empty() && freshC > 0){
            int size = rottenorg.size();
            for(int i = 0;i<size;i++){
                vector<int>rotten = rottenorg.front();
                rottenorg.pop();
                for(vector<int>dir : directions){
                    int x = rotten[0] + dir[0];
                    int y = rotten[1] + dir[1];
                    if(x>=0&&x<n && y>=0 && y<m && grid[x][y]==1){
                        grid[x][y]=2;
                        freshC--;
                        rottenorg.push({x,y});
                    }
                }
            }
            min++;
        }
        return freshC == 0 ? min: -1;
    }
};