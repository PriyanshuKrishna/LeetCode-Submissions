class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(),ans=0;
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(citations[i]<i+1)
                break;
            ans=i+1;
        }
        return ans;
    }
};