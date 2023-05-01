string s1;
int ans=0;
void func(int i,map<string,bool>vis,int som){
    string str(1,s1[i]);
    for(int j=i+1;j<(s1.length());j++){
        if(vis[str]==0){
           
            vis[str]=1;
        func(j,vis,som+1);
        vis[str]=0;}
        string var(1,s1[j]);
        str.append(var);
    }
    if(vis[str]==0){
        ans=max(ans,som);
    }
}
class Solution {
public:
    int maxUniqueSplit(string s) {
        s1=s;
        ans=0;  map<string,bool>vis;
        func(0,vis,1);
      
        return ans;
    }
};