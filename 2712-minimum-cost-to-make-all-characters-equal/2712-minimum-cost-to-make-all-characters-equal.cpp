class Solution {
public:
    long long minimumCost(string s) {
        long long res=0;
        int i=0,n=s.length();
        while(i<n-1){
            if(s[i]!=s[i+1])
                res+=min(i+1,n-i-1);
            i++;
        }
        return res;
    }
};
