class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]=='0')  return ;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i,j+1,n,m);
        dfs(grid,vis,i,j-1,n,m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return count;
    }
};
