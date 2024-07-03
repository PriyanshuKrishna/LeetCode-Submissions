class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int hormaxi=INT_MIN,vermaxi=INT_MIN,hormini=INT_MAX,vermini=INT_MAX;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    hormaxi=max(hormaxi,j);
                    vermaxi=max(vermaxi,i);
                    hormini=min(hormini,j);
                    vermini=min(vermini,i);
                }
            }
        }
        int hori=hormaxi-hormini;
        int veri=vermaxi-vermini;
        return (hori+1)*(veri+1);
    }
};