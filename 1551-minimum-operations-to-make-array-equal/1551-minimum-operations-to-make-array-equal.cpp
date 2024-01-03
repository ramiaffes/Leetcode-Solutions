class Solution {
public:
    int minOperations(int n) {
      if(n%2==1){return (n-(n+1)/2)*((n+1)/2);}
    return (n-n/2)*(n/2);
         
    }
};