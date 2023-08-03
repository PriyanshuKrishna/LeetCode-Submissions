class Solution {
private:
    void solve(int ind,int& n,string str,vector<string>& rs,string& digits,unordered_map<char,string>& mp){
        if(ind==n)
            rs.push_back(str);
        else{
            string l=mp[digits[ind]];
            for(int i=0;i<l.length();i++){
                str.push_back(l[i]);
                solve(ind+1,n,str,rs,digits,mp);
                str.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},                     {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
        int n=digits.length();
        vector<string> rs;
        if(n==0)
            return {};
        solve(0,n,"",rs,digits,mp);
        return rs;
    }
};