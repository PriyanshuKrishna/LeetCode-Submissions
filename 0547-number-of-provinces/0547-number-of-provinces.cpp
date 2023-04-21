class Solution {
private:
    void dfs(int i,vector<vector<int>>& isConnected,vector<int>& vis,int& n){
        vis[i]=1;
        for(int j=0;j<n;j++)
            if(isConnected[i][j]==1 && vis[j]==0)
                dfs(j,isConnected,vis,n);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,isConnected,vis,n);
            }
        }
        return count;
    }
};
