class Solution {
private:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,vector<int>& dir,int &sum){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() or vis[i][j] or grid[i][j]==0) 
            return sum;
        vis[i][j]=1;
        sum+=grid[i][j];
        for(int b=0;b<4;b++){
            int nr=i+dir[b];
            int nc=j+dir[b+1];
            dfs(grid,vis,nr,nc,dir,sum);
        }
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        vector<int> dir={-1,0,+1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> vis(m,vector<int>(n,0));
                if(grid[i][j]){
                    int h=0;
                    int ans=dfs(grid,vis,i,j,dir,h);
                    maxi=max(maxi,ans);
                }
            }
        }
        return maxi;
    }
};