class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int j=nums.size()-1;
    vector<int>dp(nums.size());
    dp[j]=nums[nums.size()-1];
    for(int i1=j-1;i1>=0;i1--){
        dp[i1]=dp[i1+1];
        dp[i1]=max(dp[i1],nums[i1]);
    }
    while((j>=0)and(dp[j]<=nums[j])){
        j--;
    }
    if(j<0){
        sort(nums.begin(),nums.end());return;}
     int ans=1e9;
            int val=-1;
             for(int j1=nums.size()-1;j1>j;j1--){
                 if(nums[j1]>nums[j]){
                     if(ans>nums[j1]){
                         ans=nums[j1];
                         val=j1;
                     }
                    
                 }
                 
             }
  int valeur=nums[val];
    nums[val]=nums[j];
    nums[j]=valeur;
    sort(nums.begin()+j+1,nums.end());
        
    }
};