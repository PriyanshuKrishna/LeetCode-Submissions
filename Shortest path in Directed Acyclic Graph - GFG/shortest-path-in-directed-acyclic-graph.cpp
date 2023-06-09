//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void topo(int node,vector<pair<int,int>> adj[],vector<int>& vis,stack<int>& st){
        vis[node]=1;
        for(auto it:adj[node]){
            int v=it.first;
            if(!vis[v])
                topo(v,adj,vis,st);
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int start_node=edges[i][0];
            int dest_node=edges[i][1];
            int distance=edges[i][2];
            adj[start_node].push_back({dest_node,distance});
        }
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i])
                topo(i,adj,vis,st);
        }
        
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();st.pop();
            if(dist[node]!=INT_MAX){
                for(auto it:adj[node]){
                    int v=it.first;
                    int wt=it.second;
                    if(dist[node]+wt < dist[v])
                        dist[v]=dist[node]+wt;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends