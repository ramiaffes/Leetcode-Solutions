class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>se;
        int n=1000;
        bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 prime[1]=false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
        for(int i=0;i<nums.size();i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(prime[j]){
                        se.insert(j);
                    }
                    if(prime[nums[i]/j]){
                        se.insert(nums[i]/j);
                    }
                }
            }
        }
    return se.size();
    }
};