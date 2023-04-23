class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> res(n-k+1);
        map<int,int> mi;
        for(int i=0;i<n;i++){
            int num=nums[i];
            mi[num]++;
            if(i>=k){
                int out=nums[i-k];
                mi[out]--;
                if(mi[out]==0)
                    mi.erase(out);
            }
            if(i>=k-1){
                int count=0;
                int b=0;
                for(auto& e:mi){
                    count+=e.second;
                    if(count>=x){
                        b=e.first;
                        break;
                    }
                }
                res[i-k+1]=b<0?b:0;
            }
        }
        return res;
    }
};
