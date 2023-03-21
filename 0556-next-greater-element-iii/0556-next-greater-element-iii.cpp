class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        long long rs=stoll(s);
        return (int)(rs>INT_MAX || rs<=n)?-1:rs;
    }
};
/*
        long m=n;
        vector<int> count(10);
        int currnum=-1,prevnum=-1;
        
        while(n>0){
            currnum=(int)n%10;
            n/=10;
            count[currnum]++;
            if(prevnum>currnum){
                int num=currnum+1;
                while(count[num]==0)
                    num++;
                count[num]--;
                n=n*10+num;
                for(int i=0;i<10;i++){
                    while(count[i]-- > 0)
                        n=n*10+i;
                }
                return n>INT_MAX?-1:(int)n;
            }
            prevnum=currnum;
        }
        return -1;
        
        */