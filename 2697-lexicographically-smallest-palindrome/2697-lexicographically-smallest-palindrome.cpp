class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0,n=s.length()-1;
        while(i<=n){
            s[i]=min(s[i],s[n]);
            s[n]=s[i];
            i++;n--;
        }
        return s;
    }
};