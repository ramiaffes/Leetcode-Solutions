class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>hashing;
        int som=0;
        for(int i=0;i<(nums.size()-1);i++){
            for(int j=i+1;j<nums.size();j++){
                hashing[nums[i]*nums[j]]++;
            }
        }
    for(auto v:hashing){
        som+=(hashing[v.first]*(hashing[v.first]-1))*4;
    }
    return som;
    }
};