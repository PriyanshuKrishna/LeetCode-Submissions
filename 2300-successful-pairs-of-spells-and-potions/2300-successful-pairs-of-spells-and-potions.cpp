class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(),potions.end());
        int n=potions.size(),m=spells.size();
        for(int i=0;i<m;i++){
            long long t=spells[i];
            int low=0,high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(potions[mid]*t>=success)
                    high=mid-1;
                else 
                    low=mid+1;
            }
            res.push_back(n-1-high);
        }
        return res;
    }
};