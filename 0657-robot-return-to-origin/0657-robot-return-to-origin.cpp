class Solution {
public:
    bool judgeCircle(string s) {
        int n=s.length();
        int r=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='U')       r--;
            else if(s[i]=='D')  r++;
            else if(s[i]=='L')  c--;
            else if(s[i]=='R')  c++;
        }
        if(r==0 && c==0) 
            return true;
        else 
            return false;
    }
};