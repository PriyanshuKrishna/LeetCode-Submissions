class Solution {
private:
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int r,int c,vector<int>& dir,
                bool& flag,int n,int m){
        
        grid2[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid2[nr][nc] && !grid1[nr][nc])
                flag=false;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid2[nr][nc] && grid1[nr][nc])
                dfs(grid1,grid2,nr,nc,dir,flag,n,m);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<int> dir={-1,0,+1,0,-1};
        int count=0;
        int n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool flag=true;
                if(grid2[i][j] && grid1[i][j]){
                    dfs(grid1,grid2,i,j,dir,flag,n,m);
                    if(flag)    count++;
                }
            }
        }
        return count;
    }
};

