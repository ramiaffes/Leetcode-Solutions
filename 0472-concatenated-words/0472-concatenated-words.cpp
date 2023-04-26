map<string,bool>dp;
map<string,bool>vis1;   map<string,bool>vis;
void func(string s){
    vis1[s]=1;
    for(int i=0;i<(s.length()-1);i++){
        string str=s.substr(0,i+1);
        string str2=s.substr(i+1,s.length()-(i+1));
        if((vis[str])and(vis[str2])){
            dp[s]=1;
            vis1[s]=1;
            return;
        }
    if(vis[str]==0)continue;
    if(vis1[str2]==0)func(str2);
    dp[s]=dp[s]or(vis[str]and(dp[str2]));
    if(dp[s]==true)return;
    }
}
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
     dp.clear();
        vis.clear();
        vis1.clear();
        vector<string>res;
        for(int i=0;i<words.size();i++){
            vis[words[i]]=1;
        }
    for(int i=0;i<words.size();i++){
        if(vis1[words[i]]==0)func(words[i]);
        if(dp[words[i]]==1){
            res.push_back(words[i]);
        }
    }
    
    
    return res;
    }
};