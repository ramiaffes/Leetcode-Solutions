class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long int>dp(questions.size());
        dp[questions.size()-1]=questions[questions.size()-1][0];
        if(questions.size()==1)return dp[questions.size()-1];
        for(int i=(questions.size()-2);i>=0;i--){
            if((i+questions[i][1]+1)>=questions.size()) {dp[i]=max(dp[i+1],(long long )questions[i][0]);continue;}
            dp[i]=max(dp[i+1],questions[i][0]+dp[i+questions[i][1]+1]);
        }
    long long int ans=0;
    for(auto v:dp){ans=max(ans,v);}
    return ans;
    }
};