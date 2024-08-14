class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)return 1;
        vector<int>::iterator ip;
        ip = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(), ip));
        int i=0;
        int som1=0;
        int som2=0;
        int res=nums.size();
        while(i<(nums.size()-1)){
                if(nums[i+1]>nums[i]){
                    
                    som1++;if(som1>=2)res--;
                    som2=0;
                }
            else{ som2++;if(som2>=2)res--;som1=0;}
            i++;
        }
    return res;
    }
};