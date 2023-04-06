#define ppi pair<int,pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<int> dir={-1,0,+1,0,-1};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int di=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1)  return di;
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neff=max(abs(heights[nr][nc]-heights[r][c]),di);
                    if(neff<dist[nr][nc]){
                        dist[nr][nc]=neff;
                        pq.push({neff,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};