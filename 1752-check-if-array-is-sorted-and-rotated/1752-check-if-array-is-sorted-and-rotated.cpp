class Solution {
public:
    bool check(vector<int>& nums) {
        int ans=0;
        int ans2=1e9;
       for(int i=0;i<nums.size();i++){
            ans=max(ans,nums[i]);
            ans2=min(ans2,nums[i]);
        }
        
        bool test=false;
        for(int i=0;i<(nums.size()-1);i++){
            if(nums[i]==ans){
                if((nums[i+1]!=ans2)and(nums[i+1]!=ans))return false;
                test=true;
                
            }
            else{
                if(nums[i]>nums[i+1]){
                    
                    return false;}
                    if(test==true){
                        if((nums[i+1]>nums[0])or(nums[i]>nums[0]))return false;
                    }
            }
        }
        return true;
    }
};