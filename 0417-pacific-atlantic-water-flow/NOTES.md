class Solution {
private:
void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,int i,int j,int& m,int& n){
vis[i][j]=true;
if(i-1>=0 && vis[i-1][j]!=true && heights[i-1][j]>=heights[i][j])
dfs(heights,vis,i-1,j,m,n);
if(i+1<m && vis[i+1][j]!=true && heights[i+1][j]>=heights[i][j])
dfs(heights,vis,i+1,j,m,n);
if(j-1>=0 && vis[i][j-1]!=true && heights[i][j-1]>=heights[i][j])
dfs(heights,vis,i,j-1,m,n);
if(j+1<n && vis[i][j+1]!=true && heights[i][j+1]>=heights[i][j])
dfs(heights,vis,i,j+1,m,n);
}
public:
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
vector<vector<int>> res;
int m=heights.size(),n=heights[0].size();
vector<vector<bool>> pac(m,vector<bool>(n));
vector<vector<bool>> alt(m,vector<bool>(n));
for(int i=0;i<m;i++){
dfs(heights,pac,i,0,m,n);
dfs(heights,alt,i,n-1,m,n);
}
for(int j=0;j<n;j++){
dfs(heights,pac,0,j,m,n);
dfs(heights,alt,m-1,j,m,n);
}
for(int i=0;i<m;i++){
for(int j=0;j<n;j++)
if(pac[i][j] && alt[i][j])
res.push_back({i,j});
}
return res;
}
};
​
​