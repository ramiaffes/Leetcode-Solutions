int ans=0;
map<int,int>dp;
map<int,bool>vis;
vector<int> coins1;
void func(int som){
    if(vis[som]==1)return;
    if(som==0){
        dp[0]=0;
        vis[0]=1;
        return;
    }
    else if(som<0){
        dp[som]=1e9;
        vis[som]=1;
        return;
        
    }
    else{
    dp[som]=1e9;
    vis[som]=1;
    for(int i=0;i<coins1.size();i++){
        if(vis[som-coins1[i]]==0){
    func(som-coins1[i]);}
        dp[som]=min(dp[som],1+dp[som-coins1[i]]);
        
    }
    return ;}
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        
        vis.clear(); sort(coins.begin(),coins.end());
        coins1=coins;
       
        func(amount);
        if(dp[amount]==1e9)return -1;
        return dp[amount];
    }
};