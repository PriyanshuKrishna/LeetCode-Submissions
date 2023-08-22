class Solution {
public:
    string convertToTitle(int num) {
        string res="";
        while(num>0){
            num--;
            int rem=num%26;
            num/=26;
            res+=('A'+rem);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
