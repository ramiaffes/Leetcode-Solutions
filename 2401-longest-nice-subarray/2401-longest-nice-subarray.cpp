class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<vector<int>>vect(nums.size());
        map<int,int>hashing;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=0){
                vect[i].push_back(nums[i]%2);
                nums[i]/=2;
            }
        }
    int ans=0;
    for(int i=0;i<nums.size();i++){
        int gh=vect[i].size();
        ans=max(ans,gh);
    }
    for(int i=0;i<nums.size();i++){
        while(vect[i].size()<ans){
            vect[i].push_back(0);
        }
    }
    int i=0;
    int j=0;
        int ans1=0;
    int som=ans;
   while(j<vect.size()){
        for(int d=0;d<vect[j].size();d++){
            if(vect[j][d]==1){
                if(hashing[d]==1)som--;
                hashing[d]++;
            }
        }
      while((i<=j)and(som<ans)){
          for(int d=0;d<vect[i].size();d++){
            if(vect[i][d]==1){
                if(hashing[d]==2)som++;
                hashing[d]--;
            }
      }
      i++;}
      ans1=max(ans1,j-i+1);
      j++;
    }
    
    
    return ans1;
    
    
    }
};