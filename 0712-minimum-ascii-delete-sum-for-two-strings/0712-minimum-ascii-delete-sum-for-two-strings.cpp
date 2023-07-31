class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n=s.size();
        int m=t.size();
        int sum1=0,sum2=0;
        for(auto it:s) sum1+=it;
        for(auto it:t) sum2+=it;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=s[i-1]+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return ((sum1+sum2) - 2*dp[n][m]);
    }
};