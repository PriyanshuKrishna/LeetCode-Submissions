//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        distance[0][0]=grid[0][0];
        vector<int> dir{-1,0,+1,0,-1};
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dir[i];
                int ncol=col+dir[i+1];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                    if(dist+grid[nrow][ncol]<distance[nrow][ncol]){
                        distance[nrow][ncol]=dist+grid[nrow][ncol];
                        pq.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return distance[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends