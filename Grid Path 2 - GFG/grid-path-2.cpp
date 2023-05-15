//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        int mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(m,-2));
        if(grid[n-1][m-1]==1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                if((i==0 || j==0) && grid[i][j]!=1) dp[i][j]=1;
                else{
                    int down=0,right=0;
                    if(i>0 && grid[i-1][j]!=1) down=dp[i-1][j];
                    if(j>0 && grid[i][j-1]!=1) right=dp[i][j-1];
                    dp[i][j]=(down+right)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends