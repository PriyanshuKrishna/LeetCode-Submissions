class compare{
public:
    bool operator()(int a,int b){
        string s1=to_string(a),s2=to_string(b);
        return s1+s2 > s2+s1;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare());
        string s="";
        for(auto it:nums){
            s+=to_string(it);
        }
        return (s[0]=='0')?"0":s;
    }
};


