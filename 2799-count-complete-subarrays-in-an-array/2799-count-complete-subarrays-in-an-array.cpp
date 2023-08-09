class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
      map<int,int>vis;
      set<int>arr;
        int som=0;
        int i=0;
        
        for(int j=0;j<nums.size();j++){
            arr.insert(nums[j]);
        }
      for(int j=0;j<nums.size();j++){
          vis[nums[j]]++;
          if(vis.size()<arr.size())continue;
          while((i<=j)and(vis[nums[i]]>1)){vis[nums[i]]--;
              i++;
              
              
          }
        som+=(i+1);
         
      }
    return som;
    
      
    }
};