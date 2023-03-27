//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& path,vector<int>& check){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(path[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,adj,vis,path,check);
        }
        vector<int> safe;
        for(int i=0;i<n;i++){
            if(check[i]==1)
                safe.push_back(i);
        }
        return safe;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends