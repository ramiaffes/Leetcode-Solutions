class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,bool>vis;
        map<int,int>hashing;
        int n=nums.size();
        int val=n-1;
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            dp[i]+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(vis[nums[i]]==1){
                val=i-1;break;
            }
            vis[nums[i]]=1;
            hashing[nums[i]]=i;
        }
        int som=0;
        int ans=0;
        int ans1=-1;
        for(int i=0;i<=val;i++){
            som+=nums[i];
        }
        ans=max(ans,som);
    for(int i=0;i<n;i++){
        val++;
        if(val==n){
            break;
        }
        som+=nums[val];
        if(vis[nums[val]]==0){
            if(ans1==-1)ans=max(ans,som);
            else ans=max(ans,som-dp[ans1]);
            hashing[nums[val]]=val;
            
        }
        else{
            ans1=max(ans1,hashing[nums[val]]);
            ans=max(ans,som-dp[ans1]);
            hashing[nums[val]]=val;
        }
vis[nums[val]]=1;
    }

    return  ans;
    }
};