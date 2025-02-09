class Solution {
  int countBadPairs(List<int> nums) {
      var vis={};
      int n=nums.length;
      for(int i=0;i<n;i++){
          if(vis.containsKey(nums[i]-i)==false){vis[nums[i]-i]=1;}
          else{
          vis[nums[i]-i]++;
          }
      }
     int som=0;
      int som1=0;
     for(var key in vis.keys){
         if(vis[key] is int){
             som1=vis[key];
         }
         som+=(((som1-1)*som1)~/2);
     }
     return(((n*(n-1))~/2)-som);
     
  }
}