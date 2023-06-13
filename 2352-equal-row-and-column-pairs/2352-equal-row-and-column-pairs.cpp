class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=to_string(grid[j][i])+"#";
            }
            mp[str]++;
        }
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=to_string(grid[i][j])+"#";
            }
            if(mp[str])
                count+=mp[str];
        }
        return count;
    }
};