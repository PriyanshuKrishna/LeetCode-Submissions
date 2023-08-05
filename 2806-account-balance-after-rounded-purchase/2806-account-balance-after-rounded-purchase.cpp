class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int at=p/10;
        if(p%10>=5)
            at++;
        at*=10;
        return 100-at;
    }
};