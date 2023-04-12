class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    int it=i,jt=j;
                    vector<int> temp;
                    while(it<n && jt<m){
                        temp.push_back(mat[it][jt]);
                        it++;jt++;
                    }
                    it=i,jt=j;
                    sort(temp.begin(),temp.end());
                    int h=0;
                    while(it<n && jt<m){
                        vis[it][jt]=1;
                        arr[it][jt]=temp[h];
                        it++;jt++;h++;
                    }
                }
            }
        }
        return arr;
    }
};