class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,l=0,r=1,n=intervals.size();
        while(r<n){
            if(intervals[l][1]<=intervals[r][0])
                l=r,r++;
            else if(intervals[l][1]<=intervals[r][1])
                count++,r++;
            else if(intervals[l][1]>intervals[r][1])
                count++,l=r,r++;
        }
        return count;
    }
};
