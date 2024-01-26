class Solution {
public:
    map<pair<int,pair<int,int>>,bool>vis;
    map<pair<int,pair<int,int>>,long long int>dp;
    void func(int m, int n, int maxMove, int i, int j){
        vis[make_pair(maxMove,make_pair(i,j))]=1;
        if((i<0)or(j<0)or(n<=j)or(m<=i)){
            dp[make_pair(maxMove,make_pair(i,j))]=1;
            return;
            
        }
        if(maxMove==0)return;
        if((vis[make_pair(maxMove-1,make_pair(i+1,j))]==0))
        func(m,n,maxMove-1,i+1,j);
        dp[make_pair(maxMove,make_pair(i,j))]+=dp[make_pair(maxMove-1,make_pair(i+1,j))]%1000000007;
        
        if((vis[make_pair(maxMove-1,make_pair(i,j+1))]==0)){
        func(m,n,maxMove-1,i,j+1); }
         dp[make_pair(maxMove,make_pair(i,j))]+=dp[make_pair(maxMove-1,make_pair(i,j+1))]%1000000007;
        if((vis[make_pair(maxMove-1,make_pair(i,j-1))]==0))
        func(m,n,maxMove-1,i,j-1);
        dp[make_pair(maxMove,make_pair(i,j))]+=dp[make_pair(maxMove-1,make_pair(i,j-1))]%1000000007;
        if((vis[make_pair(maxMove-1,make_pair(i-1,j))]==0))
        func(m,n,maxMove-1,i-1,j);
       
        dp[make_pair(maxMove,make_pair(i,j))]+=dp[make_pair(maxMove-1,make_pair(i-1,j))]%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.clear();
        vis.clear();
        func(m,n,maxMove,startRow,startColumn);
        return dp[make_pair(maxMove,make_pair(startRow,startColumn))]%1000000007;
    }
};