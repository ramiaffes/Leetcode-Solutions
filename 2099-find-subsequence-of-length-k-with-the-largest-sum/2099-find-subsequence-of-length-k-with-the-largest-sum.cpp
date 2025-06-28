class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>nums1(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        map<int,int>vis;
        for(int i=(nums.size()-k);i<=(nums.size()-1);i++){
            vis[nums[i]]+=1;
        }
    vector<int>res;
    for(int i=0;i<nums1.size();i++){
        if(vis[nums1[i]]>0){res.push_back(nums1[i]);vis[nums1[i]]--;}
        
    }
    return res;
    }
};