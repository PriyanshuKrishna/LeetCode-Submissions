class Solution {
public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i<0 || j<0 )  return 0;
        
        if(dp[i][j]!=-1)  return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j]=s[i]+solve(i-1,j-1,s,t,dp);
        
        return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int sum1=0,sum2=0;
        for(auto it:s1) sum1+=it;
        for(auto it:s2) sum2+=it;
        return (sum1+sum2)-2*solve(n-1,m-1,s1,s2,dp);
    }
};