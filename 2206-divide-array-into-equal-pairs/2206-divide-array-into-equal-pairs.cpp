class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<long long int,long long int>hashing;
        for( long long int i(0);i<nums.size();i++){
            hashing[nums[i]]++;
        }
    bool test=true;
    for(auto v:hashing){
        if(hashing[v.first]%2!=0){test=false;break;}
    }
        return test;
    }
};