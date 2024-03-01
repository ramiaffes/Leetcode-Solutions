class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>dp(nums.size());
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=dp[i-1];
            if(nums[i]<=nums[i-1])
            dp[i]+=1;
            else dp[i]=1;
        }
    vector<int>dp1(nums.size());
    dp1[nums.size()-1]=1;
    for(int i=nums.size()-2;i>=0;i--){
            dp1[i]=dp1[i+1];
            if(nums[i]<=nums[i+1])
            dp1[i]+=1;
        else dp1[i]=1;
        }
    vector<int>res;
    for(int i=1;i<(nums.size()-1);i++){
        if((dp1[i+1]>=k)and(dp[i-1]>=k)){
            res.push_back(i);
        }
    }
    return res;
    
    }
};