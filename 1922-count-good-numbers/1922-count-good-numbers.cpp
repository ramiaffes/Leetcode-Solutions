class Solution {
public:
    int countGoodNumbers(long long n) {
        long long p=1;
        for(long long i=0;i<n;i++){
           if(i%2==0){
            p*=5;
            p=p%1000000007;
           }
           else{
            p*=4;
            p=p%1000000007;
           }

        }
     return p;
        
    }
};