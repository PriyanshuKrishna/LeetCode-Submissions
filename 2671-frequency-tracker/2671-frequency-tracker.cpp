class FrequencyTracker {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> mps;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number)!=mp.end())
            mps[mp[number]]--;
        mp[number]++;
        mps[mp[number]]++;
    }
    
    
    void deleteOne(int number) {
        if(mp.find(number)!=mp.end() && mp[number]>0){
            mps[mp[number]]--;
            mp[number]--;
            mps[mp[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return (mps[frequency]>0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
