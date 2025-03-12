class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto it =lower_bound(nums.begin(),nums.end(),0);
        auto it1 =upper_bound(nums.begin(),nums.end(),0);
        int val1=it-nums.begin();
        int val2=(nums.end()-it1);
        return max(val1,val2);
    }
};