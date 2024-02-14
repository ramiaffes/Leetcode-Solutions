class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
       long long  int som=0;
        int ans=1e9;
        for(int i=0;i<nums.size();i++){
            som+=nums[i];
        }
        int val=target/som;
        int newtarget=target-val*som;
        if(newtarget==0){return val*nums.size();}
        vector<int>nums2;
        for(int i=0;i<nums.size();i++){
            nums2.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            nums2.push_back(nums[i]);
        }
        int i1=0;
        int j1=0;
         som=0;
        while(j1<nums2.size()){
            som+=nums2[j1];
            while((i1<=j1)and(som>newtarget)){
                som-=nums2[i1];
                i1++;
            }
        if(i1>j1){
            i1=j1+1;
        }
        else{
            if((j1-i1+1)<=nums.size()){
                if(som==newtarget){
                    ans=min(ans,j1-i1+1);
                }
            }
        }
        j1++;
        }
    if(ans==1e9)return -1;
    return(ans+val*nums.size());
    
        
        
        
        
    }
};