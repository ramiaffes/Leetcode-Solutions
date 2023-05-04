class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        map<int,vector<int>>hashing;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                hashing[2].push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                hashing[1].push_back(nums[i]);
            }
            else{
                hashing[0].push_back(nums[i]);
            }
        }
    int val=0;
    for(auto v:hashing){
        for(auto v1:v.second){
            nums[val]=v1;
            val++;
        }
    }
    return nums;
    }
};