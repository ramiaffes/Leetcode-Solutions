class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<int>cost1(nums.size());
        vector<pair<int,int>>nums1(nums.size());
        for(int i=0;i<nums.size();i++){
            nums1[i].first=nums[i];
            nums1[i].second=cost[i];
        }
        sort(nums1.begin(),nums1.end());
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cost1[i]=nums1[i].second;
        }
        cost=cost1;
        vector<long long int>dp(nums.size());
        vector<long long int>dp1(nums.size());
        dp1[0]=cost[0];
        for(int i=1;i<dp.size();i++){
            dp1[i]=dp1[i-1];
            dp1[i]+=cost[i];
        }
        dp[0]=0;
        for(int i=1;i<dp.size();i++){
            dp[i]+=dp[i-1];
            dp[i]+=(nums[i]-nums[i-1])*dp1[i-1];
        }
    vector<long long int>dp2(nums.size());
    dp2[nums.size()-1]=cost[nums.size()-1];
    for(int i=nums.size()-2;i>=0;i--){
            dp2[i]=dp2[i+1];
            dp2[i]+=cost[i];
        }
    vector<long long int>dp3(nums.size());
    dp3[nums.size()-1]=0;
    for(int i=nums.size()-2;i>=0;i--){
            dp3[i]+=dp3[i+1];
            dp3[i]+=(nums[i+1]-nums[i])*dp2[i+1];
        }
    long long int ans=1e18;
    for(int i=0;i<nums.size();i++){
        ans=min(ans,dp3[i]+dp[i]);
    }
    return ans;
    }
    
};