class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
      int tot=1<<nums.size();
	int som=0;
    int ans=0;
    map<int,int>hashing;
	for(int mask=0;mask<tot;mask++){
		som=0;
		for(int i=0;i<nums.size();i++){
			int f=1<<i;
			if(mask&f){
				som|=nums[i];
				}
			}
    if(som!=0)
        hashing[som]++;
        ans=max(ans,som);
			}
    return hashing[ans];
		
	
		  
        
    
    }
};