class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int j=0;
        int i=0;
        int som=0;
        int val=0;
        map<int,int>hashing;
        map<int,int>hashing1;
        map<int,bool>vis;

    while(j<nums.size()){
        if(vis[nums[j]])hashing1[hashing[nums[j]]]--;
        hashing[nums[j]]++;
        hashing1[hashing[nums[j]]]++;
         vis[nums[j]]=1;
        if((hashing.size()-hashing1[0])<k){j++;continue;}
        if((hashing.size()-hashing1[0])>k)val=i;
        while((i<=j)and((hashing.size()-hashing1[0])>k)){
             if(vis[nums[i]])hashing1[hashing[nums[i]]]--;
        hashing[nums[i]]--;
        hashing1[hashing[nums[i]]]++;
            i++;
            val++;
        }
        
       while((i<=j)and(hashing.size()-hashing1[0])==k){
            if(vis[nums[i]])hashing1[hashing[nums[i]]]--;
        hashing[nums[i]]--;
        hashing1[hashing[nums[i]]]++;
            i++;
        }
        i--; 
     if(vis[nums[i]])hashing1[hashing[nums[i]]]--;
        hashing[nums[i]]++;
        hashing1[hashing[nums[i]]]++;
        
  

    som+=(i-val+1);
       
        j++;
    }
    return som;
    
    }
};