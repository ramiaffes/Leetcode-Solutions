map<char,vector<char>>adj;
map<pair<char,int>,long long int>dp;
map<pair<char,int>,bool>vis;
int som1=0;
void dfs(char u,int som){ vis[make_pair(u,som)]=1;
    if(som==(1)){
        dp[make_pair(u,1)]=1;
        return;
    }
   
    for(auto v:adj[u]){
        if(vis[make_pair(v,som-1)]==0)dfs(v,som-1);
        dp[make_pair(u,som)]+=(dp[make_pair(v,som-1)]%1000000007);
    }
}
class Solution {
public:
    int countVowelPermutation(int n) {
        adj.clear();
        dp.clear();
        vis.clear();
        adj['a'].push_back('e');
        adj['e'].push_back('a');
        adj['e'].push_back('i');
        adj['o'].push_back('i');
        adj['o'].push_back('u');
        adj['u'].push_back('a');
        adj['i'].push_back('a');
         adj['i'].push_back('o');
         adj['i'].push_back('u');
        adj['i'].push_back('e');
    dfs('i',n);
    dfs('a',n);
    dfs('e',n);
    dfs('o',n);
    dfs('u',n);
    return (dp[make_pair('o',n)]%1000000007+dp[make_pair('e',n)]%1000000007+dp[make_pair('i',n)]%1000000007+dp[make_pair('a',n)]%1000000007+dp[make_pair('u',n)]%1000000007)%1000000007;
    }
};