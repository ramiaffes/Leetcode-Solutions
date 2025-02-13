class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        queue<long long int>qu;
        sort(nums.begin(),nums.end());
       int i=0;
       int res=0;
       while(i<(nums.size()-1)){
            if(qu.empty()){if(nums[i]>=k)break;}
            else if((nums[i]>=k)and(qu.front()>=k))break;
            if(qu.empty()){
                res++;
                qu.push(min((long long)nums[i],(long long)nums[i+1])*2+max((long long)nums[i],(long long)nums[i+1]));
                i+=2;
                continue;
            }
            else{
                if(nums[i+1]<qu.front()){
                    res++;
                qu.push(min((long long)nums[i],(long long)nums[i+1])*2+max((long long)nums[i],(long long)nums[i+1]));
                i+=2;
                continue;

                }
                else{
                    res++;
                    qu.push(min((long long)nums[i],qu.front())*2+max((long long)nums[i],qu.front()));
                    qu.pop();


                }
            }
            i++;
            
            
        }
    if(qu.empty()){
    if((i<nums.size())and(nums[i]<k)){return res+1;}}
   else if((i<nums.size())and((nums[i]<k)or(qu.front()<k)))return res+1;
    return res;
    }
};