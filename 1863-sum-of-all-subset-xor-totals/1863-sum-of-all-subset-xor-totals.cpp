class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int tot=1<<nums.size();
        int som1=0;
        int som=0;
        bool test=false;
	for(int mask=0;mask<tot;mask++){
         som=0;
        test=false;
		for(int i=0;i<nums.size();i++){
			int f=1<<i;
			if(mask&f){
                if(test==false){
                    som=nums[i];
                    test=true;
                }
                else{
				som^=nums[i];}
				}
			}
    som1+=som;
			}
	return som1;
    }
};