class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,q;
        int n=senate.length();
        for(int i=0;i<n;i++){
            if(senate[i]=='R')
                r.push(i);
            else
                q.push(i);
        }
        while(!r.empty() && !q.empty()){
            int r_ind=r.front();r.pop();
            int q_ind=q.front();q.pop();
            if(r_ind<q_ind)
                r.push(r_ind+n);
            else
                q.push(q_ind+n);
        }
        return (r.size()>q.size())?"Radiant":"Dire";
    }
};