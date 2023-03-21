class RandomizedSet {
private:
    vector<int> res;
    unordered_map<int,int> ump;
public:
    RandomizedSet() {
    
    }
    
    bool insert(int val) {
        if(ump.find(val)!=ump.end()) 
            return false;
        else{
            res.push_back(val);
            ump[val]=res.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(ump.find(val)==ump.end()) 
            return false;
        else{
            int last=res.back();
            res[ump[val]]=res.back();
            res.pop_back();
            ump[last]=ump[val];
            ump.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return res[rand()%res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 