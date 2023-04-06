class Solution {
private:
    void dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==1)  
            return;
        grid[r][c]=1;
        vector<int> dir={-1,0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            dfs(grid,nr,nc);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 ||i==n-1 || j==m-1) && grid[i][j]==0)
                    dfs(grid,i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1)  
                    continue;
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};