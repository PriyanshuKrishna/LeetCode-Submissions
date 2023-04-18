class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0] || grid[n-1][n-1])  return -1;
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto it=q.front();q.pop();
            auto distance=it.first;
            auto r=it.second.first;
            auto c=it.second.second;
            if(r==n-1 and c==n-1) return distance;
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc] && distance+1<dist[nr][nc]){
                        dist[nr][nc]=1+distance;
                        q.push({1+distance,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};