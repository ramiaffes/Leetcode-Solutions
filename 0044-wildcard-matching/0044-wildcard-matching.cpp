class Solution {
public:
    map<pair<int,int>,bool>dp;
    map<pair<int,int>,bool>vis;
    string s;
    string p;
    void func(int i,int j){
        vis[make_pair(i,j)]=1;
        if((i==s.length())and(j==p.length())){dp[make_pair(i,j)]=1;return ;}
        if((j==p.length())and(i<s.length())){
            return ;
        }
        if((i==s.length())and(j<p.length())){
            if(p[j]=='*'){
                if(vis[make_pair(i,j+1)]==0)func(i,j+1);
                dp[make_pair(i,j)]=dp[make_pair(i,j+1)];
                return ;
            } 
            else return ;}
        if(s[i]==p[j]){
                if(vis[make_pair(i+1,j+1)]==0)func(i+1,j+1);
                dp[make_pair(i,j)]= dp[make_pair(i+1,j+1)];
                return ;
            
        }
        else if(p[j]=='*'){ 
                if(vis[make_pair(i+1,j+1)]==0)func(i+1,j+1);
                if(vis[make_pair(i+1,j)]==0)func(i+1,j);
                if(vis[make_pair(i,j+1)]==0)func(i,j+1);
                dp[make_pair(i,j)]=dp[make_pair(i+1,j+1)]or dp[make_pair(i+1,j)]or dp[make_pair(i,j+1)];
        return;
        }
        else if(p[j]=='?'){ 
        if(vis[make_pair(i+1,j+1)]==0)func(i+1,j+1);
        dp[make_pair(i,j)]=dp[make_pair(i+1,j+1)];
               return;
        }
        else {
            return;
        }
        return ;
    }
    bool isMatch(string s1, string p1) {
       dp.clear();
       vis.clear();
       s=s1;
       p=p1;
       func(0,0);
       return dp[make_pair(0,0)];
    }
};