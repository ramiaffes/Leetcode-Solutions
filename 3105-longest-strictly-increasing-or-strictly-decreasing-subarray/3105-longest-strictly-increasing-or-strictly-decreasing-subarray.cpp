class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        vector<int>res1;
        bool test=false;
        for(int i=0;i<(nums.size()-1);i++){
            if(nums[i]<nums[i+1]){
                res1.push_back(1);test=true;}
                else if(nums[i]>nums[i+1]){
                    res1.push_back(0);test=true;
                }
                else{res1.push_back(2);}
                
            }
        if(test==false)return 1;
        
    int som=1;
    int ans=1;
    for(int i=1;i<res1.size();i++){
        if((res1[i]==res1[i-1])and(res1[i]!=2)){som++;}
        else som=1;
        ans=max(ans,som);

    }
    return (ans+1);

    }
};