class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long int som=0;
        vector<long long int>dp(nums.size());
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=dp[i-1];
            dp[i]+=nums[i];
        }
        map<int,long long int>hashing;
        vector<long long int>dp2(nums.size());
        dp2[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            dp2[i]=dp2[i+1];
            dp2[i]+=nums[i];
        }
        hashing.clear();
        vector<long long int>dp3(nums.size());
        map<int,bool>vis;
        dp3[nums.size()-1]=nums[nums.size()-1];
        hashing[0]=nums[nums.size()-1];
        vis[0]=1;
        for(int i=nums.size()-2;i>=0;i--){
      if(vis[(nums.size()-i-1)%k]==0)hashing[(nums.size()-i-1)%k]=1e9;
      hashing[(nums.size()-i-1)%k]=min(dp2[i],hashing[(nums.size()-i-1)%k]);
      dp3[i]=hashing[(nums.size()-i-1)%k]; 
         vis[(nums.size()-i-1)%k]=1; 
        }
        long long int ans=-1e9;
        if(nums.size()%k==0){
            ans=max(ans,dp[nums.size()-1]);
        }
        
        for(int i=0;i<nums.size();i++){
            if((i+k+1)>=nums.size())break;
            cout<<dp3[2]<<endl;
            ans=max(ans,dp[nums.size()-1]-dp3[(i+k+1)]-dp[i]);
        }
        for(int i=0;i<(nums.size()-1);i++){
            if((i+1)%k==nums.size()%k){
            ans=max(ans,dp[nums.size()-1]-dp[i]);}
        }
        for(int i=1;i<nums.size();i++){
            if((nums.size()-i)%k==nums.size()%k){
            ans=max(ans,dp[nums.size()-1]-dp2[i]);}
        }
        return ans;



    

    












    
    
    
  
    }
};
