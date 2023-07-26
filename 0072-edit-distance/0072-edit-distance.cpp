class Solution {
public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i==s.length())
            return t.length()-j;
        if(j==t.length())
            return s.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int rs=0;
        if(s[i]==t[j])
            return solve(i+1,j+1,s,t,dp);
        else{
            int insert=1+solve(i,j+1,s,t,dp);
            int delet=1+solve(i+1,j,s,t,dp);
            int replace=1+solve(i+1,j+1,s,t,dp);
            rs=min({insert,delet,replace});
        }
        return dp[i][j]=rs;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(0,0,word1,word2,dp);
    }
};
