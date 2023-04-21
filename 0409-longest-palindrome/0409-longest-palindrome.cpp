class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128);
        for(auto c:s)
            count[c]++;
        int ans=0;
        for(auto it:count){
            ans+=(it/2)*2;
            if(ans%2==0 && it%2==1)
                ans++;
        }
        return ans;
    }
};