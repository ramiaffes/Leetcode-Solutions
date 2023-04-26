map<pair<int,int>,bool>vis;
int res=1e6;
map<int,int>hashing;
void func(int som,int n,int som1){
    vis[make_pair(som,som1)]=1;
    for (int i=(int)sqrt(n);i>=1;i--){
        som+=i*i;
        som1++;
if(som<n){
    if((vis[make_pair(som,som1)]==0)and(som1<res)){
    func(som,n,som1);}
}
else if(n==som){res=min(res,som1);}
        
        
    som-=i*i;
    som1--;
    }


}
class Solution {
public:
    int numSquares(int n) {
vis.clear();
       
        res=1e6;
        func(0,n,0);
        return res;
    }
};