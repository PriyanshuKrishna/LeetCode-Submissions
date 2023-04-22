class Solution {
private:
    bool checkIsArithmetic(vector<int>& temp){
        int n=temp.size();
        if(n==2)    return true;
        int diff=temp[1]-temp[0];
        for(int i=2;i<n;i++)
            if(temp[i]-temp[i-1]!=diff)
                return false;
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> rs;
        int m=l.size();
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            vector<int> temp;
            for(int j=start;j<=end;j++)
                temp.push_back(nums[j]);
            sort(temp.begin(),temp.end());
            if(checkIsArithmetic(temp))
                rs.push_back(true);
            else
                rs.push_back(false);
        }
        return rs;
    }
};
