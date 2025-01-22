class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
    bool prime[101];
    memset(prime, true, sizeof(prime));
    prime[1]=false;
 
    for (int p = 2; p * p <= 100; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 100; i += p)
                prime[i] = false;
        }
    }
    int ans1=nums.size();
    int ans2=-1;
    for(int i=0;i<nums.size();i++){
        if(prime[nums[i]]){ans1=min(ans1,i);ans2=max(ans2,i);}
    }
    return ans2-ans1;


    }
};