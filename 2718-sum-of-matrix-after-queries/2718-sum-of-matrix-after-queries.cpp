class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum=0;
        // vector<vector<int>> nums(n,vector<int>(n,0));
        int sze=queries.size();
        unordered_set<int>strow;
        unordered_set<int>stcol;
        for(int i=sze-1;i>=0;i--){
            long long type=queries[i][0];
            long long val=queries[i][2];
            long long ind=queries[i][1];
            if(type==1){
                 if(stcol.count(ind)!=0)
                    continue;
                else{
                    sum+=(n-strow.size())*val;
                    stcol.insert(ind);
                }
            }
            else{
                if(strow.count(ind)!=0)
                    continue;
                else{
                    sum+=(n-stcol.size())*val;
                    strow.insert(ind);
                }
            }
        }
        return sum;
        
    }
};
