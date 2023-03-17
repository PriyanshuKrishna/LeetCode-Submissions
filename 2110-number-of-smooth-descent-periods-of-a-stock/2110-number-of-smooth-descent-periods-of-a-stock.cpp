class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=n,tmp=0;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                tmp++;
                ans+=tmp;
            }
            else
                tmp=0;
        }
        return ans;
    }
};