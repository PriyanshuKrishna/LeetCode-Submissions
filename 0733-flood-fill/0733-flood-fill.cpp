class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int row,int col,int delrow[],
                                                        int delcol[],int incolor,int color){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==incolor && 
                ans[nrow][ncol]!=color)
                dfs(image,ans,nrow,ncol,delrow,delcol,incolor,color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int incolor=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(image,ans,sr,sc,delrow,delcol,incolor,color);
        return ans;
    }
};
