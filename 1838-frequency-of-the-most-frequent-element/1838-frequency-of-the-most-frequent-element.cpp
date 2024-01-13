class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    int ans=1;
    sort(nums.begin(),nums.end());
    int i=0;
    int j=1;
    long long int som=0;
    while(j<(nums.size())){
        long long int val=nums[j]-nums[j-1];
        som+=(val)*(j-i);
        while((i<=j)and(som>k)){
            som-=(nums[j]-nums[i]);
            i++;
        }
    ans=max(ans,j-i+1);
    j++;
    }
    return ans;
        
    
        
    }
};