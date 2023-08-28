class Solution {
public:
bool solve(int& n,vector<int>& stones,int cur_ind,int prev_ind,
vector<vector<int>>& dp,unordered_map<int,int>& mp){
if(cur_ind==n-1)
return true;
if(dp[cur_ind][prev_ind]!=-1)
return dp[cur_ind][prev_ind];
bool result=false;
for(int k=prev_ind-1;k<=prev_ind+1;k++){
if(k>0){
int next_ind=stones[cur_ind]+k;
if(mp.find(next_ind)!=mp.end()){
result=result || solve(n,stones,mp[next_ind],k,dp,mp);
}
}
}
return dp[cur_ind][prev_ind]=result;
}
bool canCross(vector<int>& stones) {
int n=stones.size();
if(stones[1]!=1)
return false;
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
mp[stones[i]]=i;
}
vector<vector<int>> dp(n,vector<int>(n,-1));
return solve(n,stones,0,0,dp,mp);
}
};