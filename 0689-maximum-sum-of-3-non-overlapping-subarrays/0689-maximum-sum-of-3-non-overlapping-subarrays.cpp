class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>dp(nums.size());
        int som=0;
        for(int i=0;i<(k-1);i++){
            dp[i]=0;
            som+=nums[i];
        }
    vector<int>dp3(nums.size());
        map<int,int>hashing;
        map<int,bool>vis;
    som+=nums[k-1];
    for(int i=k-1;i<nums.size();i++){
        if(i>0)
       dp[i]=max(dp[i-1],som);
        else dp[i]=som;
        if(vis[som]==0)
        hashing[som]=i-k+1;
        vis[som]=1;
        som-=nums[i-k+1];
        if(i<(nums.size()-1))
        som+=nums[i+1];
    }
    vector<int>dp1(nums.size());
        som=0;
    for(int i=nums.size()-1;i>=(nums.size()-k+1);i--){
        dp1[i]=0;
        som+=nums[i];
        dp3[i]=-1;
    }
        int ans1=0;
    som+=nums[nums.size()-k];
     for(int i=nums.size()-k;i>=0;i--){
        if(i<(nums.size()-1))
       dp1[i]=max(dp1[i+1],som);
        else dp1[i]=som;
         if(som>=ans1){
        dp3[i]=i;
         ans1=som;}
         else{
             dp3[i]=dp3[i+1];
         }
        som-=nums[i+k-1];
        if(i>0)
        som+=nums[i-1];
    }
    som=0;
    for(int i=0;i<k;i++){
        som+=nums[i];
    }
int ans=0;
int n=nums.size();
for(int i=k-1;i<n;i++){
    int val1=0;
    int val2=0;
    if(i<(n-1))
    val1=dp1[i+1];
    if(i>=k)
    val2=dp[i-k];
    
    if((val1!=0)and(val2!=0))
    ans=max(ans,val1+val2+som);
    som-=nums[i-k+1];
    if(i<(n-1))
    som+=(nums[i+1]);
    else break;
}
        som=0;
         for(int i=0;i<k;i++){
        som+=nums[i];
    }
        for(int i=k-1;i<n;i++){
    int val1=0;
    int val2=0;
    if(i<(n-1))
    val1=dp1[i+1];
    if(i>=k)
    val2=dp[i-k];
    
    if((val1!=0)and(val2!=0)){
    if(ans==(val1+val2+som)){
        vector<int>vect(3);
        vect[0]=hashing[val2];
        vect[1]=i-k+1;
        vect[2]=dp3[i+1];
        return vect;
    }}
    som-=nums[i-k+1];
    if(i<(n-1))
    som+=(nums[i+1]);
    else break;
}
    return dp;
    
    }
};