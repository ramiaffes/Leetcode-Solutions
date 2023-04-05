class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        map<pair<int,int>,int>hashing;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(hashing[make_pair(nums[j],nums[i]-nums[j])]==0)hashing[make_pair(nums[j],nums[i]-nums[j])]=1;
                hashing[make_pair(nums[i],nums[i]-nums[j])]=hashing[make_pair(nums[j],nums[i]-nums[j])]+1;
    ans=max(ans, hashing[make_pair(nums[i],nums[i]-nums[j])]);
    if(nums[i]==nums[j])break;
            }
        }
return ans;
    }
};