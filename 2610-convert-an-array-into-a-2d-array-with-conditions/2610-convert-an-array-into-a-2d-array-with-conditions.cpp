class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> arr;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        queue<pair<int,int>> q;
        for(auto it:mp){
            q.push({it.first,it.second});
        }
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                auto node=q.front();q.pop();
                int num=node.first;
                int freq=node.second;
                temp.push_back(num);
                --freq;
                if(freq>0)
                    q.push({num,freq});
            }
            arr.push_back(temp);
        }
        return arr;
    }
};