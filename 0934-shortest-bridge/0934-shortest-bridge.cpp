class Solution {
public:
    queue<pair<int, int>> q; 
    void dfs(vector<vector<int>>& grid, int i, int j) { 
        if (i<0 || i>=grid.size() || j<0 || j>=grid.size() || grid[i][j] == 2 || grid[i][j] == 0)
            return;

        grid[i][j] = 2; 
        q.push({i,j}); 
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int bfs(vector<vector<int>>& grid){ 
        int dist=0; 
        vector<int> dir={-1,0,+1,0,-1};
        bool flag=false;
        while (!q.empty()){
            int n = q.size();
            while(n-- > 0){
                auto a = q.front();q.pop();
                for (int h=0; h<4; h++) {
                    int x = dir[h] + a.first;
                    int y = dir[h+1] + a.second;
                    if (x>=0 && x<grid.size() && y>=0 && y<grid.size() && grid[x][y] == 1){
                        flag=true;
                        break;
                    }
                    
                    else if(x>=0 && x<grid.size() && y>=0 && y<grid.size() && grid[x][y] == 0){ 
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
                if(flag)  break;
            }
            if(flag)  break;
            dist++;
        }
        return dist;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1 && !flag){ 
                    dfs(grid, i, j);
                    q.push({i,j});
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        return bfs(grid); 
    }
};