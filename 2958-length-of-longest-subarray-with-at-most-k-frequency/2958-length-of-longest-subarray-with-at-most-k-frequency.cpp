class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=0;
        map<int,int>hashing;
        while(j<nums.size()){
            hashing[nums[j]]++;
            while((i<j)and(hashing[nums[j]]>k)){
                hashing[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};