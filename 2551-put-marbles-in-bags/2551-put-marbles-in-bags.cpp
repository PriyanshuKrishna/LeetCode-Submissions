class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> mx;
        priority_queue<int,vector<int>,greater<int>> mn;
        for(int i=1;i<weights.size();i++){
            mx.push(weights[i]+weights[i-1]);
            mn.push(weights[i]+weights[i-1]);
            if(mn.size()>=k){
                mn.pop();mx.pop();
            }
        }
        long long res=0;
        while(mn.size()){
            res+=mn.top()-mx.top();
            mn.pop();mx.pop();
        }
        return res;
    }
};