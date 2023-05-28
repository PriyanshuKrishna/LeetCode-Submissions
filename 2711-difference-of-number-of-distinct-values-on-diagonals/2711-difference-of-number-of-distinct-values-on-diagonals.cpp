class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=i+1,y=j+1,p=i-1,q=j-1;
                unordered_set<int> bright,tleft;
                while(x<m && y<n) {
                    bright.insert(grid[x][y]);
                    x++;y++;
                }
                while(p>=0 && q>=0) {
                    tleft.insert(grid[p][q]);
                    p--;q--;
                }
                int bottom=bright.size();
                int top=tleft.size();
                ans[i][j]=abs(bottom-top);
             }
        }
        return ans;
    }
};