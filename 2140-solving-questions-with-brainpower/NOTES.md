class Solution {
public:
long long dfs(vector<vector<int>>& questions,int i,vector<long long>& dp){
if(i>=questions.size()) return 0;
if(dp[i]) return dp[i];
int points=questions[i][0],jump=questions[i][1];
long long pick=points+dfs(questions,i+jump+1,dp);
long long notpick=dfs(questions,i+1,dp);
return dp[i]=max(notpick,pick);
}
long long mostPoints(vector<vector<int>>& questions) {
vector<long long> dp(questions.size(),0);
return dfs(questions,0,dp);
}
};
​
​