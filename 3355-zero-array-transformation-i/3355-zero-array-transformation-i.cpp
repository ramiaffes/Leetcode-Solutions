class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>queries1(queries.begin(),queries.end());
        sort(queries1.begin(), queries1.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // sort by second element
    });
        sort(queries.begin(),queries.end());
        vector<int>res1(queries.size());
        vector<int>res2(queries.size());
         for(int i=0;i<res2.size();i++){
            res2[i]=queries1[i][1];
        }
        for(int i=0;i<res1.size();i++){
            res1[i]=queries[i][0];
        }
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++){
        auto it=upper_bound(res1.begin(),res1.end(),i);
        if(res1.end()==it)continue;
        res[i]=res1.end()-it+1;
        }
        for(int i=0;i<nums.size();i++){
        auto it=lower_bound(res2.begin(),res2.end(),i);
        if((it-res2.begin()-1)==-1)continue;
        res[i]+=it-res2.begin()-1;
        }
        for(int i=0;i<nums.size();i++){
            
            if((queries.size()-res[i])<nums[i])return false;
        }
        return true;


    }
};