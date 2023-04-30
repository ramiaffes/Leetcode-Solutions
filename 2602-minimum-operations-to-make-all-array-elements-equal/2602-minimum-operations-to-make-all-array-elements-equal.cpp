class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long >answers(queries.size());
        vector<long long int>dp(nums.size());
         dp[0]=0;
        for(int i=1;i<dp.size();i++){
            dp[i]+=dp[i-1];
            long long int val10=(nums[i]-nums[i-1]);
            val10*=i;
            dp[i]+=val10;
        }
    vector<long long int>dp3(nums.size());
    dp3[nums.size()-1]=0;
    for(int i=nums.size()-2;i>=0;i--){
            dp3[i]+=dp3[i+1];
        long long int val10=(nums[i+1]-nums[i]);
            val10*=(nums.size()-i-1);
            dp3[i]+=val10;
        }
   
        
    for(int i=0;i<queries.size();i++){
        auto it=upper_bound(nums.begin(),nums.end(),queries[i]);
      
        int val=it-nums.begin()-1;
       int val1=it-nums.begin();
        if((val>=0)and(nums[val]==queries[i])){ 
            answers[i]=dp[val]+dp3[val];
        }
        else{
            answers[i]=0;
        if(it!=nums.begin()){
            
        answers[i]+=dp[val];
            long long int val10=(queries[i]-nums[val]);
            val10*=(val+1);
        answers[i]+=val10;
        }
        if(it!=nums.end()){
        answers[i]+=dp3[val1];
            long long int val10=-(queries[i]-nums[val1]);
            val10*=(nums.size()-val1);
        answers[i]+=val10;} }
   }
    return answers;
    

    }
};