class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vector<int> dir={-1,0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dir[i];
            int nc=col+dir[i+1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                dfs(nr,nc,grid,vis);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        /*for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j])
                dfs(0,j,grid,vis);
            if(grid[n-1][j]==1 && !vis[n-1][j])
                dfs(n-1,j,grid,vis);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0])
                dfs(i,0,grid,vis);
            if(grid[i][m-1]==1 && !vis[i][m-1])
                dfs(i,m-1,grid,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;i<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
            }
        }*/
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0,j,grid,vis);
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,grid,vis);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,grid,vis);
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,grid,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};

