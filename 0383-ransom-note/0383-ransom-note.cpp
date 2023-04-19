class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int m_count[26] = {0};
        for(int i=0; i<magazine.size(); i++){
            m_count[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if((m_count[ransomNote[i]-'a']--)<=0)
                return false;
        }
        return true;
    }
};