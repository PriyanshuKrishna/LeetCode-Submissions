class Solution {
private:
bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int r,int c,vector<int>& dir){
int n=grid1.size(),m=grid1[0].size();
grid1[r][c]=0;
grid2[r][c]=0;
for(int i=0;i<4;i++){
int nr=r+dir[i];
int nc=c+dir[i+1];
if(nr>=0 && nr<n && nc>=0 && nc<m && grid2[nr][nc] && !grid1[nr][nc]){
// cout<<nr<<" "<<nc<<endl;
return false;
}
else if(nr>=0 && nr<n && nc>=0 && nc<m && grid1[nr][nc] && grid2[nr][nc])
return dfs(grid1,grid2,nr,nc,dir);
}
return true;
}
public:
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
vector<int> dir={-1,0,+1,0,-1};
int count=0;
int n=grid1.size(),m=grid1[0].size();
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid1[i][j] && grid2[i][j] ){
if(dfs(grid1,grid2,i,j,dir)==true){
// cout<<i<<" "<<j<<endl;
count++;
}
}
}
}
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++) cout<<grid2[i][j]<<" ";
//     cout<<endl;
// }
return count;
}
};