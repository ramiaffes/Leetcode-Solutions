class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,nums[i]);
        }
    vector<int>res;
    for(int i=0;i<nums.size();i++){
        if(ans==nums[i]){
            res.push_back(i);
        }
    }
    int ans2=0;
    map<int,bool>vis;
    for(auto v:res){
        int val=v;
        int som2=0; 
        while((val>=0)and(vis[val]==0)and((nums[val]&ans)-ans==0)){
            vis[val]=1;
           
            som2++;
            val--;
        }
        val=v+1;
        while((val<nums.size())and(vis[val]==0)and((nums[val]&ans)-ans==0)){
            vis[val]=1;
            som2++;
            val++;
        }
    ans2=max(ans2,som2);
    
    }
    return ans2;
    }
};