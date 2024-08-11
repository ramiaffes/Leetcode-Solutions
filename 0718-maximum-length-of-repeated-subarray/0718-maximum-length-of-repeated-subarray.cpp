class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        map<int,vector<int>>hashing;
        int som=1;
        vector<int>res1;
        for(int i=0;i<(nums1.size()-1);i++){
            if(nums1[i]==nums1[i+1]){
                som++;
            }
            else{
                res1.push_back(som);
                som=1;
            }
        }
    res1.push_back(som);
    vector<int>::iterator ip;
    ip = unique(nums1.begin(),nums1.end());
    nums1.resize(distance(nums1.begin(), ip));
     som=1;
        vector<int>res2;
        for(int i=0;i<(nums2.size()-1);i++){
            if(nums2[i]==nums2[i+1]){
                som++;
            }
            else{
                res2.push_back(som);
                som=1;
            }
        }
    res2.push_back(som);
    ip = unique(nums2.begin(),nums2.end());
    nums2.resize(distance(nums2.begin(), ip));
        for(int i=0;i<nums1.size();i++){
            hashing[nums1[i]].push_back(i);
        }
    int ans=0;
     for(int i=0;i<nums2.size();i++){
         for(auto v:hashing[nums2[i]]){
             int som=min(res1[v],res2[i]);
             ans=max(ans,som);
             int v1=v;
             for(int j=i+1;j<(nums2.size());j++){
              if((v1+1)>=(nums1.size()))break;
               
                 else if((nums1[v1+1]==nums2[j])and(res1[v1+1]==res2[j])){
                     v1++;
                     som+=res1[v1];
                     ans=max(ans,som);
                 }
                else if((nums1[v1+1]==nums2[j])and(res1[v1+1]!=res2[j])){
                    v1++;
                    som+=min(res1[v1],res2[j]);
                    ans=max(ans,som);
                    break;
                }
                else{
                    break;
                }
             }
         }
     }
    return ans;
    }
};