class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int,int>hashing;
        int j=0;
        long long int som=0;
        int ans=0;
         for(int i=0;i<nums.size();i++){
             ans=max(ans,nums[i]);
         }
        for(int i=0;i<nums.size();i++){
            hashing[nums[i]]++;
            bool test=false;
            while((j<=i)and(hashing[ans]>=k)){
                hashing[nums[j]]--;
                test=true;
                j++;
            }
        
        if(test==true){j--;hashing[nums[j]]++;}
        if(hashing[ans]>=k){
            som+=(j+1);
        }
            
        
        }
    return som;
    }
};