class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=0,res=0;
        for(int i=1;i<prices.size();i++){
            sell=prices[i];
            if((sell-buy)>0)
                res=max(res,(sell-buy));
            else
                buy=min(buy,prices[i]);
        }
        return res;
    }
};