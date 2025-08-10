class Solution {
public:
   
    long long splitArray(vector<int>& nums) {
     bool prime[100000 + 1]; memset(prime, true, sizeof(prime));
    prime[1]=false;
    prime[0]=false;
    for (int p = 2; p * p <= nums.size(); p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= nums.size(); i += p)
                prime[i] = false;
        }
    }
    long long som1=0;
    long long som2=0;
    for(int i=0;i<nums.size();i++){
        if(prime[i]==0){som1+=nums[i];}
        else som2+=nums[i];
    }
       return abs(som1-som2) ;
    }
};