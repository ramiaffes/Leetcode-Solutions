int ans=1e9;
 vector<vector<int>>dp;
vector<int>dp1;
map<int,bool>vis;
map<int,bool>vis2;
bool test2=false;
bool test=false;
void func(int i,int n){
    int ans1=1e9;
    vis[i]=1;
    if((i!=0)and(dp[i][n-1]==true)){
        if(dp1[i]==1){vis2[i]=true;}
        dp1[i]=min(dp1[i],0);
       
    }
    for(int j=i+1;j<(n);j++){
        if(dp[i][j-1]==true){
    if((i!=0)and(dp[j][n-1]==true)){
        if(dp1[j]==1){vis2[j]=true;}
        dp1[j]=0;
        dp1[i]=1;
        return  ;
    }
       else {
           if(vis[j]==0)func(j,n);
           ans1=min(ans1,1+dp1[j]);

           if((i==0)and((dp1[j]==1)or(vis2[j]==true))){test=true;}
           
       }
        }    
    } 
    

dp1[i]=ans1;
   
return ;
    
}
class Solution {
public:
    bool checkPartitioning(string s) {
          dp.clear();
        dp1.clear();
        test=false;
        test2=false;
        dp1.resize(s.length());
        vis.clear();
        vis2.clear();
        int n=s.length();
        ans=1e9;
        dp.resize(s.length(),vector<int>(s.length()));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<s.length();j++){
                if((i+1)>(j-1)){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                dp[i][j]=(s[i]==s[j])and(dp[i+1][j-1]);}


            }
        }
        
        func(0,n);
        cout<<dp1[0]<<endl;
    return (dp1[0]==2)or((dp1[0]<2)and((test==true)or(test2==true)))or((dp[0][s.length()-1]==true)and(s.length()>=3));
    }
};