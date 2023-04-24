class Solution {
private:
    void solve(vector<int>& temp,vector<vector<int>>& res,int n,int k,int index){
        if(temp.size()==k){
            res.push_back(temp);
            return ;
        }
        for(int j=index;j<=n;j++){
            temp.push_back(j);
            solve(temp,res,n,k,j+1);
            temp.pop_back();
        }  
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(temp,res,n,k,1);
        return res;
    }
};