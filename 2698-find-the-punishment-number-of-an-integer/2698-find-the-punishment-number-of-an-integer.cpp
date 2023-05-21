class Solution {
private:
    bool check(string& str,int& k,int sum,int s){
        if(sum>k) return false;
        if(s==str.length()){
            if(k==sum) return true;
            else return false;
        }
        bool ans=false;
        int x=0;
        for(int i=s;i<str.length();i++){
            x=x*10+(str[i]-'0');
            ans |= check(str,k,sum+x,i+1);
        }
        return ans;
    }
public:
    int punishmentNumber(int n) {
        int count=1;
        string str;
        for(int i=2;i<=n;i++){
            str=to_string(i*i);
            if(check(str,i,0,0))
                count+=(i*i);
        }
        return count;
    }
};
