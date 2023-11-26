class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> arr;
        int index=0;
        for(auto it:words){
            if(count(it.begin(),it.end(),x))
                arr.push_back(index);
            index++;
        }
        return arr;
    }
};