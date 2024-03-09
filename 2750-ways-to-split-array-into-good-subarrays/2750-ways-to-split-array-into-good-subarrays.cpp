class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int som=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
               som++;
            }
            else{
                res.push_back(som);
                som=0;
            }
        }
    if(res.size()==0)return 0;
    long long int p=1;
    if(som!=0){
        res.push_back(som);  
              }
    if(nums[0]==1){
        res.insert(res.begin(),1);
    }
      if(nums[nums.size()-1]==1){
        res.push_back(1);
    }
    for(int i=1;i<(res.size()-1);i++){
        p*=(res[i]+1);
        p=p%1000000007;
    }
    
    
    return p%1000000007;
    }
};