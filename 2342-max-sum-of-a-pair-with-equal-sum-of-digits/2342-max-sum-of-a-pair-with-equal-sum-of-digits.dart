class Solution {
  int maximumSum(List<int> nums) {
      var vis={};
      var m={};
      for(int i=0;i<nums.length;i++){
          var som=0;
          int valeur=nums[i];
          if(vis[nums[i]]==null){
              vis[nums[i]]=1;
          }
          else
          vis[nums[i]]++;
          while(valeur!=0){
              som+=valeur%10;
              valeur=valeur~/10;
          }
         if(m.containsKey(som)==false)
         m[som]=[nums[i]];
         else m[som].add(nums[i]);}
         for( var key in m.keys){
             m[key].sort();
         }
      int ans=-1;
        for( var key in m.keys){
            if(m[key].length==1)continue;
            ans=max(ans,m[key][m[key].length-1]+m[key][m[key].length-2]);
        }
      
     
         
         
         
   return ans;   
  }
}