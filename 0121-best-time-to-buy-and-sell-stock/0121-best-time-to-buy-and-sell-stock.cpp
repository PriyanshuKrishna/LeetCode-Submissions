class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyday=prices[0],sellday=0,res=0;
        for(int i=1;i<prices.size();i++){
            sellday=prices[i];
            if((sellday-buyday)>0)
                res=max(res,(sellday-buyday));
            else
                buyday=prices[i];
        }
        return res;
    }
};