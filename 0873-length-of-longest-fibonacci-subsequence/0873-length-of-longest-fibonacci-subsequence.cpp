class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<pair<int,int>,int>dp;
        map<int,bool>vis;
        vis[arr[0]]=1;
         int ans=0;
        for(int i=1;i<arr.size();i++){
            auto it=lower_bound(arr.begin(),arr.end(),arr[i]/2.0);
            for(int j=it-arr.begin();j<i;j++){
                if((vis[arr[i]-arr[j]]==1)and(arr[i]!=2*arr[j])and(arr[i]<2*arr[j])){
                    dp[make_pair(arr[j],arr[i])]=max(dp[make_pair(arr[j],arr[i])],1+dp[make_pair(min(arr[j],arr[i]-arr[j]),max(arr[j],arr[i]-arr[j]))]);
    ans=max(ans,dp[make_pair(arr[j],arr[i])]+2);
                }
            }
        vis[arr[i]]=1;

        }
   
    
    return ans;
            }
};