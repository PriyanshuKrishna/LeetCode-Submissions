class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int sum=0,n=s.length();
            if(n%2==0){
                for(int j=0;j<n/2;j++){
                    sum+=s[j]-s[n-j-1];
                }
                if(sum==0)
                    ans++;
            }
        }
        return ans;
    }
};
