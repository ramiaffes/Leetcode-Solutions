class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int j=0;
        int i=0;
        long long int res=0;
        long long int som=0;
        int len=0;
        while(j<nums.size()){
            som+=nums[j];
            len++;
            while((i<=j)and((som*len)>=k)){
                som-=nums[i];
                len--;
                i++;
            }
    
        if(((som*len)>=k)or(j<i)){
            i=j+1;
            j++;
            som=0;
            len=0;
            continue;
        }
        else res+=(j-i+1);

 j++;
        }
    return res;
    }
};