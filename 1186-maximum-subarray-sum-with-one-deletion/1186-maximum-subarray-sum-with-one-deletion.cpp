class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1)return arr[0];
        vector<int>dp1(arr.size());
        dp1[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            dp1[i]=dp1[i-1];
            dp1[i]+=arr[i];
        }  vector<int>dp2(arr.size());
    dp2[0]=dp1[0];
  
         for(int i=1;i<arr.size();i++){
            dp2[i]=min(dp1[i],dp2[i-1]);
        }
    vector<int>dp3(arr.size());
     dp3[arr.size()-1]=arr[arr.size()-1];
    for(int i=arr.size()-2;i>=0;i--){
            dp3[i]=dp3[i+1];
            dp3[i]+=arr[i];
        }
    vector<int>dp4(arr.size());
    dp4[arr.size()-1]=dp3[arr.size()-1];
    
       for(int i=arr.size()-2;i>=0;i--){
            dp4[i]=min(dp3[i],dp4[i+1]);
        }
    int res=-1e9;
    for(int i=1;i<(arr.size()-1);i++){
        int val=-1e9;
        if(i<(arr.size()-2))
        val=max(dp3[i+1],dp3[i+1]-dp4[i+2]);
        else val=max(val,dp3[i+1]);
       
        int val2=-1e9;
        if(i>=2)
            val2=max(dp1[i-1],dp1[i-1]-dp2[i-2]); 
            else val2=max(val2,dp1[i-1]); 
        res=max(res,val+val2);
    }
    int val=-1e9;
        if(0<(arr.size()-2))
        val=max(dp3[1],dp3[1]-dp4[2]);
        else val=max(val,dp3[1]);
        res=max(res,val);
    val=-1e9;
       if((arr.size()-1)>=2)
            val=max(dp1[arr.size()-1-1],dp1[arr.size()-1-1]-dp2[arr.size()-1-2])   ; 
            else val=max(val,dp1[arr.size()-1-1]);
    for(int i=1;i<arr.size();i++){
        res=max(res,dp1[i]-dp2[i-1]);
        res=max(res,dp1[i]);
        res=max(res,dp3[i]);
        if(i<(arr.size()-1))
        res=max(res,dp3[i]-dp4[i+1]);
        
    }
        res=max(res,dp1[0]);
        res=max(res,dp3[0]);
        res=max(res,dp3[0]-dp4[1]);

    
    
return res;
    }
};