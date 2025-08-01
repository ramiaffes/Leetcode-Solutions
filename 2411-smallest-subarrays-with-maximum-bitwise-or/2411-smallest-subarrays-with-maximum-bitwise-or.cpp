class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>>vect(nums.size());
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
    vector<vector<int>>res(ans);
    for(int i=0;i<ans;i++){
        for(int j=0;j<nums.size();j++){
            if(vect[j][i]==1){
                res[i].push_back(j);
            }
        }
    }
    vector<int>answers(nums.size());
    vector<int>valeurs(ans);
        int rh=0;
    for(int i=0;i<nums.size();i++){
        rh=i;
        for(int j=0;j<ans;j++){
            while((valeurs[j]<res[j].size())and(res[j][valeurs[j]]<i)){
                valeurs[j]++;
            }
            if(valeurs[j]!=res[j].size()){
                int m=res[j][valeurs[j]];
                rh=max(rh,m);
            }
        }
    answers[i]=rh-i+1;
    }
    return answers;
    
    }
};