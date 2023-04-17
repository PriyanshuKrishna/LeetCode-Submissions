class Solution {
private:
    pair<int,int> dfs(vector<vector<int>>& land,int r,int c,vector<int>& dir,int n,int m){
        land[r][c]=0;
        pair<int,int> rs=make_pair(r,c);
        for(int i=0;i<4;i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr<0 || nr>=n || nc<0 || nc>=m || !land[nr][nc])    continue;
            pair<int,int> ans=dfs(land,nr,nc,dir,n,m);
            rs.first=max(rs.first,ans.first);
            rs.second=max(rs.second,ans.second);
        }
        return rs;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<int> dir={-1,0,+1,0,-1};
        int n=land.size(),m=land[0].size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    pair<int,int> it=dfs(land,i,j,dir,n,m);
                    temp.push_back(it.first);
                    temp.push_back(it.second);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
// simple dfs approach
