class Solution {
  void sortColors(List<int> nums) {
      var vis={};
      for(var j in nums){
          if(vis.containsKey(j)==false){
              vis[j]=1;
          }
          else
          vis[j]++;
      }
     for(int i=0;i<nums.length;i++){
         if((vis[0]!=0)&&(vis.containsKey(0)!=false)){
             nums[i]=0;
             vis[0]--;
         }
        else if((vis[1]!=0)&&(vis.containsKey(1)!=false)){
            nums[i]=1;
            vis[1]--;
        }
        else{
            nums[i]=2;
        }
     }
     
  }
}