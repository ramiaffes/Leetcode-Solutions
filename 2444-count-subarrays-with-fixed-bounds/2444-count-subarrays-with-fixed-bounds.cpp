class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int j=0;
        int i=0;
        int val=0;
       long long int som=0;
        map<int,long long int>hashing;
        while(j<nums.size()){
            hashing[nums[j]]++;
            if((nums[j]>maxK)or(nums[j]<minK)){
                i=j+1;
                j=j+1;
                hashing.clear();
                val=j;
                continue;
            }

        else{
            if((hashing[maxK]!=0)and(hashing[minK]!=0)){
                while((i<=j)and(hashing[maxK]!=0)and(hashing[minK]!=0)){
                    hashing[nums[i]]--;
                    i++;
                }
    
            i-=1;
            hashing[nums[i]]++;
            
            som+=(i-val+1);
            }
        }
        j++;
        }
    return som;
    }
};