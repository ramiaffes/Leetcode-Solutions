class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,vector<int>>dp;
        for(int i=0;i<nums.size();i++){
            int ans=0;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    int val=dp[j].size();
                   ans=max(ans,val);
                }
            }
        for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                     if(nums[i]%nums[j]==0){
                         if(ans==dp[j].size()){
                             for(auto v:dp[j]){
                                 dp[i].push_back(v);
                             }
                             break;
                         }
                     }
                }}
        dp[i].push_back(nums[i]);
        }
     int ans=0;
    for(int i=0;i<nums.size();i++){
        int val=dp[i].size();
        ans=max(ans,val);
    }
    for(int i=0;i<nums.size();i++){
        if(ans==dp[i].size()){
            return dp[i];
        }
    }
      return dp[0];
    }
};