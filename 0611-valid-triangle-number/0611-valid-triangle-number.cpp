class Solution {
public:
    int triangleNumber(vector<int>& nums) {if(nums.size()<=2)return 0;
        sort(nums.begin(),nums.end());
        int d=0;
        int res=0;
        for(int i=0;i<(nums.size()-2);i++){
            d=nums.size()-1;
            if(nums[i]==0)continue;
            for(int j=nums.size()-2;j>=i+1;j--){
                while((d>j)and((nums[j]+nums[i])<=nums[d])){
                    d--;
                }
            if(d<(j+1))continue;
            
            res+=(d-j);

            }
        }
    return res;
    }
};