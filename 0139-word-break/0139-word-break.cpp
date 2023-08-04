class Solution {
public:
    bool solve(int ind,int &n,string &s,vector<int>& dp,unordered_set<string>& word){
        if(ind==n) return true;
        if(dp[ind]!=-1) return dp[ind];
        string tmp;
        for(int i=ind;i<n;i++){
            tmp+=s[i];
            if(word.count(tmp)){
                if(solve(i+1,n,s,dp,word))
                    return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int> dp(n,-1);
        unordered_set<string> word(wordDict.begin(),wordDict.end());
        return solve(0,n,s,dp,word);
    }
};