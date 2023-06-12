class Solution {
public:
    int countEven(int n) {
        int t=n,sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return (sum%2==0)?t/2:(t-1)/2;
    }
};
