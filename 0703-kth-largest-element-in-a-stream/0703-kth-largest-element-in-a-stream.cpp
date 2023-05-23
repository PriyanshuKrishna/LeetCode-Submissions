class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto it:nums)
            minheap.push(it);
    }
    int add(int val) {
        minheap.push(val);
        while(minheap.size()>size)
            minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */