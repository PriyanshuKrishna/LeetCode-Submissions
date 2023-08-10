class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=0,res=0;
        for(auto it:prices){
            sell=it;
            if((sell-buy)>0)
                res=max(res,(sell-buy));
            else 
                buy=min(buy,it);
        }
        return res;
    }
};