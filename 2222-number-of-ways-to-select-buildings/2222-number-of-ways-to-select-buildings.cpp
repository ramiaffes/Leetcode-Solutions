class Solution {
public:
    long long numberOfWays(string s) {
        vector<int>dp1(s.length());
        vector<int>dp(s.length());
        long long som=0;
        dp[0]=(s[0]=='0');
        dp1[s.length()-1]=(s[s.length()-1]=='0');
        for(int i=1;i<s.length();i++){
            dp[i]=dp[i-1];
            if(s[i]=='0'){
                dp[i]++;
            }
        }
    for(int i=s.length()-2;i>=0;i--){
            dp1[i]=dp1[i+1];
            if(s[i]=='0'){
                dp1[i]++;
            }
        }
    for(int i=1;i<(s.length()-1);i++){
        if(s[i]=='1'){
            som+=dp[i-1]*dp1[i+1];
        }
        else{
            som+=(i-dp[i-1])*(s.length()-i-1-dp1[i+1]);
        }
        
    }
    return som;
    
    }
};