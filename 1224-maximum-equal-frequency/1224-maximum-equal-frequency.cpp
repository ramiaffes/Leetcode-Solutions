class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int,int>hashing;
        int ans=0;
        int ans1=1e9;
        int res=0;
        map<int,bool>vis;
        set<int>se;
        map<int,int>hashing1;
        for(int i=0;i<nums.size();i++){
            if(ans1==hashing[nums[i]]){
                if(hashing1[ans1]>=2){
                    ans1=hashing[nums[i]];
                }
            else{
                ans1=hashing[nums[i]]+1;
            }
            }
            else if(ans1>hashing[nums[i]]){
                ans1=hashing[nums[i]]+1;
            }
            
            else{
                ans1=ans1;
            }
            if(vis[nums[i]]==1)
            hashing1[hashing[nums[i]]]--;
            vis[nums[i]]=1;
            se.insert(nums[i]);
            hashing[nums[i]]++;
            hashing1[hashing[nums[i]]]++;
            ans=max(ans,hashing[nums[i]]);
          
            if((ans1==(ans-1))and(hashing1[ans]==1)and(hashing1[ans1]==se.size()-1)){
                res=max(res,i+1);
            }
             if((ans1==1)and(hashing1[ans]==se.size()-1)and(hashing1[ans1]==1)){
                res=max(res,i+1);
            }
            if((ans1==1)and(ans1==ans)){
                res=max(res,i+1);
            }
            if((hashing1[ans]==1)and(ans==ans1)){
                res=max(res,i+1);
            }
            
        }
    return res;
    }
};