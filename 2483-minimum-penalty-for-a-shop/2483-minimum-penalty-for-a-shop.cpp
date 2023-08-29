class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int nofy=0,nofn=0,gu=0,h=0,res=INT_MAX,as=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') 
                nofy++;
            else
                gu++;
        }
        if(gu==0) 
            return customers.size();
        if(nofy==0) 
            return 0;
        for(int i=0;i<n;i++){  
            int h=nofy+nofn;
            if(res>h){
                res=h;
                as=i;
            }
            if(customers[i]=='Y')   nofy--;
            else    nofn++;
        }
        h=nofy+nofn;
        if(res>h){
            res=h;
            as=customers.size();
        }
        return as;
    }
};