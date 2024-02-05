class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    map<int,int>hashing;
        vector<int>res;
    for(int i=0;i<k;i++){
        hashing[nums[i]]++;
    }
    int som=0;
    for(auto v:hashing){
        if(v.first>=0)break;
        som+=hashing[v.first];
        if(som>=x){
            res.push_back(v.first);
            break;
        }
    }
   if(som<x)res.push_back(0);
   for(int i=k;i<(nums.size());i++){
       hashing[nums[i-k]]--;
       hashing[nums[i]]++;
       int som=0;
    for(auto v:hashing){
        if(v.first>=0)break;
        som+=hashing[v.first];
        if(som>=x){
            res.push_back(v.first);
            break;
        }
    }
     if(som<x)res.push_back(0);
   } 
        return res;
    }
};