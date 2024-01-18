const int N=46;
vector<int>dp(N);
map<int,bool>vis;
void func(int n){
    if(n==2){
        dp[2]=2;
        vis[2]=1;
        return;
    }
    if(n==1){
        dp[1]=1;
        vis[1]=1;
        return;
    }
    if(vis[n-1]==0){
         func(n-1);
    }
    if(vis[n-2]==0){
        func(n-2);
    }
    dp[n]=dp[n-2]+dp[n-1];
    vis[n]=1;
    return ;
}

class Solution {
public:
    int climbStairs(int n) {
        func(n);
    return dp[n];
    }
};