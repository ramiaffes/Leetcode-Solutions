class Solution {
public:
    int maxDistinct(string s) {
        map<char,bool>vis;
        vis[s[0]]=1;
        int som=1;
        for(int i=1;i<s.length();i++){
            if(vis[s[i]]==0){
                som++;
                vis[s[i]]=1;
            }
        }
    return som;
    }
};