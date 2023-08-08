class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        map<char,set<char>>adj;
        map<char,bool>vis;
        for(int i=0;i<s.length();i++){
            adj[s[i]].insert(t[i]);
        }
        for(auto v:adj){
           
           if(adj[v.first].size()>1)return false;  
           for(auto v1:adj[v.first]){
            if(vis[v1])return false;
            vis[v1]=1;}
        }
        return true;
        }
};