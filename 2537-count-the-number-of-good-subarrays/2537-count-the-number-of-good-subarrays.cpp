class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<long long int,long long int>hashing;
        int i=0;
        int j=0;
       long long  int val=0;
        long long int res=0;
        while(j<nums.size()){
            val+=hashing[nums[j]];
            hashing[nums[j]]++;
            while((i<j)and((val-hashing[nums[i]]+1)>=k)){
                hashing[nums[i]]--;
                val-=(hashing[nums[i]]);
                i++;
            }
        if(val>=k){
        res+=(i+1);
       }
        j++;
        }
    return res;

    }
};