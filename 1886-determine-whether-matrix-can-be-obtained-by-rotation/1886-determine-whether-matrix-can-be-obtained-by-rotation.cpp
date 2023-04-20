class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ch[4];
        memset(ch,true,sizeof(ch));
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j])
                    ch[0]=false;
                if(mat[i][j]!=target[n-j-1][i]) 
                    ch[1]=false;
			    if(mat[i][j]!=target[n-i-1][n-j-1]) 
                    ch[2]=false;
			    if(mat[i][j]!=target[j][n-i-1]) 
                    ch[3]=false;
            }
        }
        return ch[0] || ch[1] || ch[2] || ch[3];
    }
};