class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> hori(n,0);
        vector<int> veri(m,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]==0){
                    hori[j]=1;
                    veri[i]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hori[j] || veri[i])
                    matrix[i][j]=0;
            }
        }
    }
};