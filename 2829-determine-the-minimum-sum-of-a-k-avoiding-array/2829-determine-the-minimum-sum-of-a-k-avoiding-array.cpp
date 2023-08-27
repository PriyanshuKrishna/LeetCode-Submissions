class Solution {
public:
    int minimumSum(int n, int k) {
        int ind=1,size=0,sum=0;
        unordered_map<int,int> mp;
        while(size<n){
            if(mp.count(k-ind)){
                ind++;
                continue;
            }
            sum+=ind;
            mp[ind]++;
            ind++;
            size++;
        }
        return sum;
    }
};