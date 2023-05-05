class Solution {
private:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int& sum){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        int temp=grid[i][j];
        sum+=temp;
        ans=max(ans,sum);
        grid[i][j]=0;
        dfs(grid,i-1,j,sum);
        dfs(grid,i+1,j,sum);
        dfs(grid,i,j-1,sum);
        dfs(grid,i,j+1,sum);
        grid[i][j]=temp;
        sum-=temp;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int t=0;
                    dfs(grid,i,j,t);
                }
            }
        }
        return ans;
    }
};
