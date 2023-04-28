
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
       sort(satisfaction.begin(),satisfaction.end());
       vector<int>dp(satisfaction.size());
        int som=2; int ans=0;
        dp[0]=satisfaction[0];
       for(int i=1;i<dp.size();i++){
           dp[i]=dp[i-1];
           dp[i]+=som*satisfaction[i];
           ans=max(ans,dp[i]);
           som++;
           
       }
    vector<int>dp1(satisfaction.size());
    dp1[satisfaction.size()-1]=satisfaction[satisfaction.size()-1];
    for(int i=satisfaction.size()-2;i>=0;i--){
        dp1[i]=dp1[i+1];
        dp1[i]+=satisfaction[i];
    }
        vector<int>dp2(satisfaction.size());
    dp2[satisfaction.size()-1]=satisfaction[satisfaction.size()-1];
     
        for(int i=satisfaction.size()-2;i>=0;i--){
        dp2[i]=dp2[i+1]+dp1[i+1];
        dp2[i]+=satisfaction[i];
        ans=max(ans,dp2[i]);
    }
   
   for(int i=0;i<(dp.size()-1);i++){
       for(int j=i+1;j<dp.size();j++){
           ans=max(dp[i]+dp2[j]+i*dp1[j],ans);
       }
   }
return ans;
    
    
    
    
    
    
    
    

    }
};