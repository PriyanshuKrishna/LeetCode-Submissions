class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> indegree(n,0);
        for(auto it:edges){
            //adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                res.push_back(i);
        }
        return res;
    }
};