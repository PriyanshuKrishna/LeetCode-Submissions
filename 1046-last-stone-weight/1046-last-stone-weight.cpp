class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mx(stones.begin(),stones.end());
        while(mx.size()>1){
            int ma=mx.top();mx.pop();
            int mi=mx.top();mx.pop();
            if(ma!=mi)
                mx.push(ma-mi);
        }
        return mx.empty()?0:mx.top();
    }
};