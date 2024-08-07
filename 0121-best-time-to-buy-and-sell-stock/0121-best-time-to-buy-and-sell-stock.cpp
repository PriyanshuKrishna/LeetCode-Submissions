class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN,mini=INT_MAX,diff=0;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            diff=prices[i]-mini;
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};