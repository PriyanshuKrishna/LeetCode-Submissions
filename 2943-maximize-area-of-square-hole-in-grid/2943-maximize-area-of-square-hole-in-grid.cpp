class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxh=1,maxv=1;
        int cur=1;
        sort(hBars.begin(),hBars.end());
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1)
                cur++;
            else
                cur=1;
            maxh=max(maxh,cur);
        }
        cur=1;
        sort(vBars.begin(),vBars.end());
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1)
                cur++;
            else
                cur=1;
            maxv=max(maxv,cur);
        }
        return min(maxh+1,maxv+1)*min(maxh+1,maxv+1);
    }
};