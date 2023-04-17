class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> dir={-1,0,+1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.empty() || q.size()==n*n)
            return -1;
        int distance=-1;
        while(!q.empty()){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                auto it=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int nr=it.first+dir[i];
                    int nc=it.second+dir[i+1];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc]){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};