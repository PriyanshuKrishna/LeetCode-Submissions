class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto it:prerequisites)
            adj[it[1]].push_back(it[0]);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count==n)  
            return true;
        else
            return false;
    }
};
