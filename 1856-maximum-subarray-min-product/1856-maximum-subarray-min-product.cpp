class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
   
    int som=1;
    vector<long long int>res;
    for(int i=0;i<(nums.size()-1);i++){
        if(nums[i]==nums[i+1]){
            som++;
        }
        else{
            res.push_back(som);
            som=1;
        }
    }
    res.push_back(som);
     auto ip = unique(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(), ip));
     vector<long long int>dp(nums.size());
     vector<long long int>dp1(nums.size());
     vector<long long int>dp2(nums.size());
     vector<long long int>dp3(nums.size());
    dp[0]=res[0]*nums[0];
    for(int i=1;i<nums.size();i++){
        dp[i]=dp[i-1];
        dp[i]+=res[i]*nums[i];
    }
        dp1[nums.size()-1]=res[nums.size()-1]*nums[nums.size()-1];
    for(int i=nums.size()-2;i>=0;i--){
        dp1[i]=dp1[i+1];
        dp1[i]+=res[i]*nums[i];
    
    }

    stack<int>st;
    st.push(0);
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]<nums[i]){
            st.push(i);
        }
        else{
            while((not(st.empty()))and(nums[st.top()]>nums[i])){
                dp2[st.top()]=i+1;
                st.pop();
            }
        st.push(i);
        }
    }
    stack<int>st1;
    st1.push(nums.size()-1);
     for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]>nums[i+1]){
            st1.push(i);
        }
        else{
            while((not(st1.empty()))and(nums[st1.top()]>nums[i])){
                dp3[st1.top()]=i+1;
                st1.pop();
            }
        st1.push(i);
        }
    }
    long long int ans=0;
    for(int i=0;i<nums.size();i++){
        
    long long int val1=dp3[i];
        long long int val2=dp2[i];
        long long int res=dp1[0];
        if(val1!=0){
            res-=dp[val1-1];
        }
        if(val2!=0){
            res-=dp1[val2-1];
        }
    
    ans=max(ans,res*nums[i]);
    
    }
    
    
    
    
    
        return ans%1000000007;
    }
};