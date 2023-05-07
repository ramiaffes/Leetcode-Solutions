class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int i=0;
        long long int som=0;
        vector<long long int>power(nums.size());
        power[0]=1;
        for(int i=1;i<nums.size();i++){
            power[i]=power[i-1];
            power[i]*=2;
            power[i]=power[i]%1000000007;
        }
        while(j>=0){
            while((i<=j)and((nums[i]+nums[j])<=target)){
                i++;
            }
            if(i==0){j--;continue;}
            i--;
            if(i==j){som++;
                    som+=power[j-i]*(power[i]-1);
                    som=som%1000000007;}
            else{
                som+=power[j-1-i]*(power[i+1]-1);
                som=som%1000000007;
            }           
            j--;
        }
    return som%1000000007;
    }
};