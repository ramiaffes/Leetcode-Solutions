class Solution {
public:
    map<pair<int,int>,int>dp;
    map<pair<int,int>,bool>vis;
    string s1;
    void func(int i,int j){
        vis[make_pair(i,j)]=1;
       if(i==j){
           dp[make_pair(i,j)]=1;
           return ;
       }
    else if(i==(j-1)){
        if(s1[i]==s1[j])dp[make_pair(i,j)]=2;
        else dp[make_pair(i,j)]=1;
        return ;
    }
    else{
        if(s1[i]==s1[j]){
            if(vis[make_pair(i+1,j-1)]==0)func(i+1,j-1);
            dp[make_pair(i,j)]=dp[make_pair(i+1,j-1)]+2;
            return;
        }
        else{
            if(vis[make_pair(i+1,j)]==0)func(i+1,j);
            if(vis[make_pair(i,j-1)]==0)func(i,j-1);
            dp[make_pair(i,j)]=max(dp[make_pair(i+1,j)],dp[make_pair(i,j-1)]);
            return;
        }
    }
    }
    int longestPalindromeSubseq(string s) {
        dp.clear();
        vis.clear();
        s1=s;
        func(0,s1.length()-1);
        return dp[make_pair(0,s1.length()-1)];
    }
};