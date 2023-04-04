class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>hashing;
        int som=0;
        for(int i=0;i<nums.size();i++){
            hashing[nums[i]]++;
        }
    for(auto v:hashing){
        som+=hashing[v.first]*(hashing[v.first]-1)/2;
    }
        return som;
    }
};