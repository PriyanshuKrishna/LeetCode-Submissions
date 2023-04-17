class Solution {
public:
    string reverseWords(string s) {
        string word="",res="";
        stringstream str(s);
        while(str>>word){
            reverse(word.begin(),word.end());
            res+=" "+word;
        }
        res.erase(res.begin());
        return res;
    }
};