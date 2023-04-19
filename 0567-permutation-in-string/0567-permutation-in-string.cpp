class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        bool ans=false;
        vector<int> hash(26,0),phash(26,0);
        int window=s1.length(),len=s2.length(),left=0,right=0;
        if(len<window)
            return false;
        while(right<window){
            phash[s2[right]-'a']++;
            hash[s1[right]-'a']++;
            right++;
        }
        right--;
        while(right<len){
            if(phash==hash)
                return true;
            right++;
            if(right!=len)
                phash[s2[right]-'a']++;
            phash[s2[left]-'a']--;
            left++;
        }
        return ans;
    }
};