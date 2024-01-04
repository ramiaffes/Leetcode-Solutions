class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int>val;
        for(int i=0;i<26;i++){
            val[i+97]=i+1;
        }
        for(int i=0;i<chars.length();i++){
            val[chars[i]]=vals[i];
        }
        vector<int>dp(s.length());
        dp[0]=val[s[0]];
        for(int i=1;i<s.length();i++){
            dp[i]=dp[i-1];
            dp[i]+=val[s[i]];
        }
        vector<int>dp1(s.length());
        dp1[0]=dp[0];
        for(int i=1;i<s.length();i++){
            dp1[i]=min(dp[i],dp1[i-1]);
        }
        int ans=0;
        ans=max(ans,dp[0]);
        for(int i=1;i<s.length();i++){
            ans=max(ans,dp[i]-dp1[i-1]);
            ans=max(ans,dp[i]);
        }
        
        
        return ans;
    }
};