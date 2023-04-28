class Solution {
private:
    void backtracking(string& s,int i,vector<string>& str){
        if(i==s.length()){
            str.push_back(s);
            return;
        }
        backtracking(s,i+1,str);
        if(isalpha(s[i])){
            s[i]^=(1<<5);
            backtracking(s,i+1,str);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> str;
        backtracking(s,0,str);
        return str;
    }
};

