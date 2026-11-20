class Solution {
public:
    int minimizeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=1e9;
        ans=min(ans,nums[nums.size()-2]-nums[1]);
        ans=min(ans,nums[nums.size()-1]-nums[2]);
        ans=min(ans,nums[nums.size()-3]-nums[0]);

        return ans;
    }
};