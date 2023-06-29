class Solution {
public:
int maxOperations(vector<int>& nums, int k) {
unordered_map<int,int> mp;
for(int i=0;i<nums.size();i++){
mp[nums[i]]++;
}
int count=0;
for(int i=0;i<nums.size();i++){
mp[nums[i]]--;
if(mp[nums[i]]<0) continue;
int dif=k-nums[i];
if(mp[dif]){
mp[dif]--;
count++;
}
}
return count;
}
};
/*
unordered_map<int, int> Map;
for (auto &num: nums) Map[num]++;  // count freq of nums
int ans = 0;
for(auto it=Map.begin(); it!=Map.end(); ++it){
int num = it->first, count = it->second;
if(k - num == num) ans += count/2;   // if num is half of k add half of it's count in ans
else if(Map.count(k - num)){   // find k-num in nums and add min freq of num or k-num to ans
int Min = min(count, Map[k-num]);
ans += Min;
Map[num] -= Min;
Map[k-num] -= Min;
}
}
return ans;*/