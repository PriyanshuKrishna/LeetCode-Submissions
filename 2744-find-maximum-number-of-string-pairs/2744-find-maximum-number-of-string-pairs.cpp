class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        set<string> st(words.begin(),words.end());
        int count=0;
        for(auto it:words){
            string tmp=it;
            reverse(tmp.begin(),tmp.end());
            if(tmp==it) continue;
            if(st.count(tmp)) count++;
        }
        return count/2;
    }
};