class Solution {
public:
    int addDigits(int num) {
        while(true){
            int sum=0;
            while(num!=0){
                int dig=num%10;
                sum=sum+dig;
                num=num/10;
            }
            num=sum;
            sum=0;
            if(num<10)
                return num;
        }
        return num;
    }
};