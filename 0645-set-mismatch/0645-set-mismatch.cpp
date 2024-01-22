class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>hashing;
        for(int i=0;i<nums.size();i++){
            hashing[nums[i]]++;
        }
        vector<int>res(2);
        for(int i=1;i<=nums.size();i++){
            if(hashing[i]==2){
                res[0]=i;
            }
            else if(hashing[i]==0){
                res[1]=i;
            }
        }
    return res;
    }
};