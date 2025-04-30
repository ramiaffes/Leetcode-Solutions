class Solution {
public:
    int findNumbers(vector<int>& nums) {
        map<int,int>hashing;
        for(int i=0;i<nums.size();i++){hashing[to_string(nums[i]).length()%2]++;}
        return hashing[0];
    }
};