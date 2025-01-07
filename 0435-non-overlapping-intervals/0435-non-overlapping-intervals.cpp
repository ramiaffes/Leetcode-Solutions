class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
int ans=0;
map<int,int>dp;
for(int i=0;i<(intervals.size());i++){
    dp[i]=1;
}
int val=0;
int val1=intervals[0][0];
int val2=intervals[0][1];
 for(int i=0;i<(intervals.size()-1);i++){
      if(intervals[i+1][0]<intervals[i][1]){
             if(val2<=intervals[i+1][0]){
                 val1=intervals[i+1][0];
                 val2=intervals[i+1][1];
                 dp[i+1]=dp[val]+1;
                 val=i+1;
             }
            else{
                if(val!=0)
                dp[i+1]=dp[val-1]+1;
            }
         
      }
     else{
         dp[i+1]=dp[i]+1;
         val=i+1;
         val1=intervals[i+1][0];
         val2=intervals[i+1][1];
     }
  }
    for(auto v:dp){
        ans=max(ans,v.second);
    }

      return intervals.size()-ans;  
    }
};