
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
        pq.push({0,0});
        vector<long> dist(n,1e12);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        int mod=(int)1e9+7;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int node=it.second;
            long wt=it.first;
            
            for(auto it:adj[node]){
                int adjnde=it.first;
                long edwt=it.second;
                if(edwt+wt<dist[adjnde]){
                    dist[adjnde]=edwt+wt;
                    pq.push({edwt+wt,adjnde});
                    ways[adjnde]=ways[node]%mod;
                }
                else if(edwt+wt==dist[adjnde])
                    ways[adjnde]=(ways[adjnde]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};