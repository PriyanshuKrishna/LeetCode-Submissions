class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n);
        for(auto it:roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        long long ans=0,i;
        for(i=0;i<n;i++){
            ans+=(i+1)*indegree[i];
        }
        return ans;
    }
};