class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum=0;
        // vector<vector<int>> nums(n,vector<int>(n,0));
        int m=queries.size();
        unordered_set<int>stcol,strow;
        for(int i=m-1;i>=0;i--){
            long long type=queries[i][0];
            long long val=queries[i][2];
            long long ind=queries[i][1];
            if(type){
                if(stcol.count(ind))  continue;
                sum+=(n-strow.size())*val;
                stcol.insert(ind);
                continue;
            }
            if(strow.count(ind)) continue;
            sum+=(n-stcol.size())*val;
            strow.insert(ind);
        }
        return sum;
    }
};