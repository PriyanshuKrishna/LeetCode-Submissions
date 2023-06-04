class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum=0;
        // vector<vector<int>> nums(n,vector<int>(n,0));
        int row=0,col=0,sze=queries.size();
        unordered_set<int>s;
        unordered_set<int>s1;
        for(int i=sze-1;i>=0;i--){
            int type=queries[i][0];
            int val=queries[i][2];
            int ind=queries[i][1];
            if(type==1){
                 if(s1.count(ind)!=0)
                    continue;
                else{
                    sum+=(n-row)*val;
                    col+=1;
                    s1.insert(ind);
                }
            }
            else{
                if(s.count(ind)!=0)
                    continue;
                else{
                    sum+=(n-col)*val;
                    row+=1;
                    s.insert(ind);
                }
            }
            
        }
        return sum;
        
    }
};
