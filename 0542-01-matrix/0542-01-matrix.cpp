class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,-1));
        vector<int> dir={-1,0,+1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dis[nr][nc]==-1 && !vis[nr][nc]){
                    q.push({nr,nc});
                    dis[nr][nc]=dis[r][c]+1;
                    vis[nr][nc]=1;
                }
            }
        }
        return dis;
    }
};