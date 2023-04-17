class Solution {
public:
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
vector<vector<int>> res;
int n=land.size(),m=land[0].size();
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(land[i][j]==1 && (i==0 || land[i-1][j]==0) && (j==0 || land[i][j-1]==0)){
vector<int> temp;
temp.push_back(i);
temp.push_back(j);
int l=i;
while(l<n && land[l][j]==1)
l++;
l--;
temp.push_back(l);
int k=j;
while(k<m && land[i][k]==1)
k++;
k--;
temp.push_back(k);
res.push_back(temp);
}
}
}
return res;
}
};