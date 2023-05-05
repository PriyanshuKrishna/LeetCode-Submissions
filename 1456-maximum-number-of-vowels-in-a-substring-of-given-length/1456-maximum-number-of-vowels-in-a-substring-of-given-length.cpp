class Solution {
public:
    int maxVowels(string s, int k) {
        int res=0,maxi=INT_MIN;
        int n=s.length();
        unordered_set<char> v{'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(v.count(s[i]))
                res++;
            if(i>=k && v.count(s[i-k]))
                res--;
            maxi=max(maxi,res);
        }
        return maxi;
    }
};