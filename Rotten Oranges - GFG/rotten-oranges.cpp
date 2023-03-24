//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<int> dir={-1,0,+1,0,-1};
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0)  return -1;
        if(ans==-1)  return 0;
        else return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends