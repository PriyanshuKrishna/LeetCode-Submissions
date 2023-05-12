public:
string largestNumber(vector<int>& nums) {
vector<int> adj[10];
string s="";
for(int i=0;i<nums.size();i++){
string f=to_string(nums[i]);
int fdig=(f[0]-'0');
adj[fdig].push_back(nums[i]);
}
for(int i=9;i>=0;i--){
int n=adj[i].size();
if(n==0)
continue;
else if(n>1){
sort(adj[i].begin(),adj[i].end());
for(int j=n-1;j>=0;j--){
s+=to_string(adj[i][j]);
}
}
else
s+=to_string(adj[i][0]);
}
return s;
}
};