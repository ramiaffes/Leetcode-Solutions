class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long som1=0;
        long long som2=0;
        bool test2=false;
        bool test1=false;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                test1=true;
                som1+=1;
            }
            else som1+=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0){
                test2=true;
                som2+=1;
            }
            else som2+=nums2[i];
        }
    if((test1==false)and(som1<som2))return -1;
    if((test2==false)and(som2<som1))return -1;
    return max(som1,som2);
    }
};