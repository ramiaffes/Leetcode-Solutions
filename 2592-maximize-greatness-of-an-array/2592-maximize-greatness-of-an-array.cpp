class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        vector<int>nums1(nums.begin(),nums.end());
        sort(nums1.begin(),nums1.end());
        vector<int>nums2=nums1;
        int i=0;
        int j=0;
        int som=0;
        while(i<nums1.size()){
            while((j<nums2.size())and(nums2[j]<=nums1[i])){
                j++;
            }
            if(j==nums2.size())break;
            som++;
            i++;
            j++;
        }
    return som;
    }
};