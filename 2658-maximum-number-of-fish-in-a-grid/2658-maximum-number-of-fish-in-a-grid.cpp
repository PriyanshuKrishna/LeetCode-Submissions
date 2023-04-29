class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,int m,int n,int& t){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]==0) 
            return;
        vis[i][j]=1;
        t+=grid[i][j];
        
        dfs(grid,vis,i+1,j,m,n,t);
        dfs(grid,vis,i-1,j,m,n,t);
        dfs(grid,vis,i,j+1,m,n,t);
        dfs(grid,vis,i,j-1,m,n,t);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int rs=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    int t=0;
                    dfs(grid,vis,i,j,m,n,t);
                    rs=max(rs,t);
                }
            }
        }
        return rs;
    }
};
