class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long int som=0;
        long long int som1=0;
        for(int i=0;i<nums.size();i++){
            auto it =lower_bound(nums.begin(),nums.end(),-nums[i]+lower);
            if(it==(nums.end())){
                continue;
            }
            som+=((nums.size()-(it-nums.begin())));
            if(lower<=2*nums[i])som-=1;

            
        }
         for(int i=0;i<nums.size();i++){
            auto it =lower_bound(nums.begin(),nums.end(),-nums[i]+max(lower,upper+1));
            if(it==nums.end()){
                continue;
            }
            som1+=((nums.size()-(it-nums.begin())));
             if(max(lower,upper+1)<=2*nums[i])som1--;
             
        }
    return (som/2-som1/2);
    }
};