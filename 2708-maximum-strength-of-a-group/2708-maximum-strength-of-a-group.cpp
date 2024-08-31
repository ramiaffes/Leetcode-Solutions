class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long int som1=0;
        long long int som2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)som1++;
            else if(nums[i]>0)som2++;
        }
        if(not((som2!=0)or(som1>1))and((som1+som2)!=nums.size())){return 0;}
        vector<int>nums1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums1.push_back(nums[i]);
            }
        }
        vector<long long int>dp1(nums1.size());
        vector<long long int>dp2(nums1.size());
        dp1[0]=nums1[0];
        dp2[0]=nums1[0];
        for(int i=1;i<nums1.size();i++){
            dp1[i]=nums1[i];
            dp2[i]=nums1[i];
            if(nums1[i]>0){
                for(int j=0;j<i;j++){
                    dp1[i]=max(dp1[i],dp1[j]*nums1[i]);
                    dp2[i]=min(dp2[i],dp2[j]*nums1[i]);
                }
            }
        else{
            for(int j=0;j<i;j++){
                    dp1[i]=max(dp1[i],dp2[j]*nums1[i]);
                    dp2[i]=min(dp2[i],dp1[j]*nums1[i]);
                }
        }
        }
   long long  int ans=-1e9;
    for(auto v:dp1){
        ans=max(ans,v);
    }
    return ans;
        
        
    }
};