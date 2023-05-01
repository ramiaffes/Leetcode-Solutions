vector<string>arr1;
int ans=0;
void func(int i,map<char,bool>vis,int som){
    if(i!=-1){
    ans=max(ans,som);
    for(auto v:arr1[i]){
        if(vis[v]){return;}
        vis[v]=1;
    }
    som+=arr1[i].length();
    ans=max(ans,som);}
    for(int j=i+1;j<arr1.size();j++){
        func(j,vis,som);
    }
}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        arr1=arr;
        ans=0;
        map<char,bool>vis;
        
        func(-1,vis,0);
        return ans;
    }
};