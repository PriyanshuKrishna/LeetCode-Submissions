class Solution {
private:
    void dfs(vector<vector<int>>& grid,int r,int c){
        grid[r][c]=0;
        vector<int> dir={-1,0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()
                        && grid[nr][nc]==1)
                dfs(grid,nr,nc);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || j==m-1 || i==n-1) && grid[i][j]==1) 
                    dfs(grid,i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};