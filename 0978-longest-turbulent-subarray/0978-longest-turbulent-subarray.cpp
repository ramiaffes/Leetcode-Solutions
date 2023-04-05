class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int>dp(arr.size());
        dp[0]=1;
        int val=0;
        for(int i=1;i<(arr.size());i++){
            if((val==0)and(arr[i]>arr[i-1])){
                dp[i]=dp[i-1];
                dp[i]++;
                if(i%2==0)
                val=1;
                else val=2;
            }
            else if((val==0)and(arr[i]==arr[i-1])){
                dp[i]=1;
                val=0;
            }
         else if((val==0)and(arr[i]<arr[i-1])){
                dp[i]=dp[i-1];
                dp[i]++;
             if(i%2==1)
                val=1;
                else val=2;
            }
        else if((val==1)and(arr[i]<arr[i-1])){
               
             if(i%2==1){dp[i]=dp[i-1];
                dp[i]++;
                val=1;}
                else {
                    dp[i]=2;val=2;}
            }
          else if((val==1)and(arr[i]>arr[i-1])){
               
             if(i%2==0){dp[i]=dp[i-1];
                dp[i]++;
                val=1;}
                else {
                    dp[i]=2;val=2;}
            }
         else if((val==1)and(arr[i]==arr[i-1])){
               dp[i]=1;
             val=0;
            }
         else if((val==2)and(arr[i]<arr[i-1])){
               
             if(i%2==0){dp[i]=dp[i-1];
                dp[i]++;
                val=2;}
                else {
                    dp[i]=2;val=1;}
            }
        else if((val==2)and(arr[i]>arr[i-1])){
            if(i%2==1){dp[i]=dp[i-1];
                dp[i]++;
                val=2;}
                else {
                    dp[i]=2;val=1;}
        }
          else if((val==2)and(arr[i]==arr[i-1])){
               dp[i]=1;
             val=0;
            }  
    
           
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,dp[i]);
        }
    return ans;
    }
};