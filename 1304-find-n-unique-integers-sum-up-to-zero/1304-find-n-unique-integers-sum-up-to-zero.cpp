class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ar;
        int k=1,i=0,j=n-1;
        while(i<j){
                ar.push_back(k);
                ar.push_back(-k);
                i++;j--;k++;
            }
        if(n%2)  ar.push_back(0);
        return ar;
    }
};