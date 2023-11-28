class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> st{'a','e','i','o','u'};
        int ans=0;
        for(int i=0;i<s.size();i++){
            int vow=0,con=0;
            for(int j=i;j<s.size();j++){
                if(st.count(s[j])) vow++;
                else con++;
                
                if(vow==con && (vow*con)%k==0)
                    ans++;
            }
        }
        return ans;
    }
};