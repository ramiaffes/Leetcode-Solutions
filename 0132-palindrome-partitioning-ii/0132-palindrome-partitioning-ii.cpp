int ans=1e9;
 vector<vector<int>>dp;
vector<int>dp1;
map<int,bool>vis;
void func(int i,int n){
    int ans1=1e9;
    vis[i]=1;
    if(dp[i][n-1]==true){
        dp1[i]=0;
        return ;
    }
    for(int j=i+1;j<(n);j++){
        if(dp[i][j-1]==true){
    if(dp[j][n-1]==true){
        dp1[j]=0;
        dp1[i]=1;
        return  ;
    }
       else {
           if(vis[j]==0)func(j,n);
           ans1=min(ans1,1+dp1[j]);
          
       }
        }    
    } 
    

dp1[i]=ans1;
return ;
    
}
class Solution {
public:
    int minCut(string s) {
        dp.clear();
        dp1.clear();
        dp1.resize(s.length());
        vis.clear();
        int n=s.length();
        ans=1e9;
        dp.resize(s.length(),vector<int>(s.length()));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<s.length();j++){
                if((i+1)>(j-1)){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                dp[i][j]=(s[i]==s[j])and(dp[i+1][j-1]);}


            }
        }
        
        func(0,n);
        
    return dp1[0];
    
    
    }
};