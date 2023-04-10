class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,long long>hashing;
        map<int,long long>hashing1;
        map<int,long long>hashing2;
        map<int,long long>hashing3;
        for(int i=0;i<nums.size();i++){
            hashing3[nums[i]]++;
            hashing2[nums[i]]+=i;
        }
        vector<long long>res(nums.size());
        for(int i=0;i<nums.size();i++){
            hashing[nums[i]]++;
            hashing1[nums[i]]+=i;
            res[i]=i*(hashing[nums[i]])-hashing1[nums[i]]-(hashing3[nums[i]]-hashing[nums[i]]+1)*(i)+hashing2[nums[i]]-hashing1[nums[i]]+i;
        }


        return res;
    }
};