class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        int res=1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(pairs[i][1]<pairs[j][0]){
                    dp[j]=max(dp[j],dp[i]+1);
                    res=max({res,dp[j],dp[i]+1});
                }
            }
        }
        return res;
    }
};
