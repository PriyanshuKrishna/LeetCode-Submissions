class Solution {
public:
    long long minimumPossibleSum(int n, int k) {
        int ind=1,size=0;
        long long sum=0;
        set<int> st;
        while(size<n){
            if(st.find(k-ind)!=st.end()){
                ind++;
                continue;
            }
            sum+=ind;
            st.insert(ind);
            ind++;
            size++;
        }
        return sum;
    }
};