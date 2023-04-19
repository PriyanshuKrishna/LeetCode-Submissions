class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.length(),len=0;
        vector<int> mp(256,-1);
        while(r<n){
            if(mp[s[r]]!=-1)
                l=max(mp[s[r]]+1,l);
            mp[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
