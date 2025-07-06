class FindSumPairs {
List<int> nums1=[];
   List<int> nums2=[];
   var hashing={};
  FindSumPairs(List<int> nums1, List<int> nums2) {
      this.nums1=nums1;
      this.nums2=nums2;
      for(int i=0;i<nums2.length;i++){
          if(hashing[nums2[i]]==null)hashing[nums2[i]]=1;
          else hashing[nums2[i]]++;
      }
  }
  
  void add(int index, int val) {
   if(hashing[nums2[index]]==null)  return; 
else if(hashing[nums2[index]]==1)hashing[nums2[index]]=null;
   else hashing[nums2[index]]--;
nums2[index]+=val;
if(hashing[nums2[index]]==null)hashing[nums2[index]]=1;
    else hashing[nums2[index]]++;
  }
  
  int count(int tot) {
    int res=0;
     int var1=0;
for(int i=0;i<nums1.length;i++){
    if(hashing[tot-nums1[i]] is int){var1=hashing[tot-nums1[i]] ;}
   res+= var1;
    var1=0;
}
return res;
  }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param2 = obj.count(tot);
 */