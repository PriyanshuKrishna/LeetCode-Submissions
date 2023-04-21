class Solution {
private:
void dfs(string s,int n,int& i,int & j){
for(int h=0;h<n;h++){
if(s[h]=='U') dfs(s,n,i-1,j);
else if(s[h]=='D')  dfs(s,n,i+1,j);
else if(s[h]=='L')  dfs(s,n,i,j-1);
else if(s[h]=='R')  dfs(s,n,i,j+1);
}
}
public:
bool judgeCircle(string moves) {
string s=moves;
int n=s.length();
int i=0,j=0;
dfs(s,n,i,j);
if(i==0 && j==0)  return true;
else return false;
}
};