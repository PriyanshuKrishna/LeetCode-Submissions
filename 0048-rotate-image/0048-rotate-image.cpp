class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int leng=matrix.size();
        int k=0,temp=0;
        for(int i=0;i<leng;i++){
            for(int j=k;j<leng;j++){
                if(i!=j)
                    swap(matrix[i][j],matrix[j][i]);
            }
            k++;
        }
        int t=leng-1;
        for(int i=0;i<leng;i++){
            int t=leng-1;
            for(int j=0;j<(leng/2);j++){
                swap(matrix[i][j],matrix[i][t]);
                t--;
            }
        }
    }
};