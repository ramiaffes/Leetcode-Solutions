class Solution {
public:
    map<pair<int,int>,int>dp;
    map<pair<int,int>,bool>vis;
    void func(int i,int j,vector<vector<int>> matrix){
        vis[make_pair(i,j)]=1;
        if(i==(matrix.size()-1)){
            dp[make_pair(i,j)]=matrix[i][j];
            return;
        }
        if(j>=1){
        if(vis[make_pair(i+1,j-1)]==0){
        func(i+1,j-1,matrix);}
        dp[make_pair(i,j)]=min(dp[make_pair(i,j)],dp[make_pair(i+1,j-1)]+matrix[i][j]);}
    if(j<(matrix.size()-1)){
        if(vis[make_pair(i+1,j+1)]==0){
        func(i+1,j+1,matrix);}
        dp[make_pair(i,j)]=min(dp[make_pair(i,j)],dp[make_pair(i+1,j+1)]+matrix[i][j]);}
        if(vis[make_pair(i+1,j)]==0){
        func(i+1,j,matrix);}
        dp[make_pair(i,j)]=min(dp[make_pair(i,j)],dp[make_pair(i+1,j)]+matrix[i][j]);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp.clear();vis.clear();
        int ans=1e5;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                dp[make_pair(i,j)]=1e5;
            }
        }
        for(int i=0;i<matrix.size();i++){
            func(0,i,matrix);
            ans=min(ans,dp[make_pair(0,i)]);
        }
        
    return ans;
    }
};