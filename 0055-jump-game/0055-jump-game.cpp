class Solution {
public:
    vector<int>nums1;
    bool test=false;
    int ans=0;
    void func(int i,int p){
        if(p>=(nums1.size()-1)){test=true;return;}
        for(int j=i;j<=p;j++){
            ans=max(ans,nums1[j]+j);
        }
        if(ans<(p+1))return;
        func(p+1,ans);
        return;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        test=false;
        nums1=nums;
        ans=0;
        func(0,nums1[0]);
        return test;
    }
};