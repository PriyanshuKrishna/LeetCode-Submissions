//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        vector<int> dir={-1,0,+1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            auto dis=it.first;
            auto r=it.second.first;
            auto c=it.second.second;
            q.pop();
            if(r==destination.first && c==destination.second)  return dis;
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && dis+1<dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    //if(destination.first==nr && destination.second==nc)  return 1+dis;
                    q.push({1+dis,{nr,nc}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends