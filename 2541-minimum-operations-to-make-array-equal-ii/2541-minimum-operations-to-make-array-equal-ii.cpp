class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
       long long int kn=0;
        long long int kp=0;
        if(k==0){
            if(nums1==nums2)return 0;
            else return -1;
        }
        for(int i=0;i<nums1.size();i++){
            if(abs(nums1[i]-nums2[i])%k!=0)return -1;
            if(nums1[i]>nums2[i]){
                kp+=(nums1[i]-nums2[i])/k;
            }
            if(nums1[i]<nums2[i]){
                kn+=(nums2[i]-nums1[i])/k;
            }
        }
    if(kp!=kn)return -1;
    return kp;
    }
};