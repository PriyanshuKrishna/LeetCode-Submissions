class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> mi=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                mi[j]=min(mi[j],mi[j+1])+triangle[i][j];
            }
        }
        return mi[0];
    }
};