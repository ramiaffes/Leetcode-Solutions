class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int ans=0;
        int j=0;
        while(i<nums1.size()){
          
            while((j<nums2.size())and(nums1[i]<=nums2[j])){
                j++;
            }
             
        if(j>=nums2.size()){
            j=nums2.size()-1;
        } 
           
        if(nums1[i]>nums2[j])j--;
        if(i>j){
            j=i+1;
        } 
        else{

            ans=max(ans,j-i);
        }
            i++;
        }
    return ans;
        
    }
};