class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;
    int curr;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        int ans;
        if(!pq.empty()){
            ans=pq.top();
            st.erase(ans);
            pq.pop();
        }
        else{
            ans=curr;
            curr+=1;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(curr<=num || st.find(num)!=st.end())  return;
        pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */