
vector<int> nums1;
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
{
 
    if (l <= ss && r >= se)
        return st[node];
 
  
    if (se < l || ss > r)
        return -1e6;
 
 
    int mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}
 

int getMax(int* st, int n, int l, int r)
{
    
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
 

int constructSTUtil( int ss, int se,
                    int* st, int si)
{
   
    if (ss == se)
    {
        st[si] = nums1[ss];
        return nums1[ss];
    }
 
  
    int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil( ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil( mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}
 

int* constructST( int n)
{
    
    int x = (int)(ceil(log2(n)));
 
   
    int max_size = 2 * (int)pow(2, x) - 1;
 
   
    int* st = new int[max_size];
 
    
    constructSTUtil( 0, n - 1, st, 0);
 
   
    return st;
}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        nums1=nums;
         int* st = constructST( n);
        vector<int>res;
          for(int i=0;i<nums.size();i++){
              
              if((i+k)<=nums.size()){
                  res.push_back(getMax(st, n, i, i+k-1));
              }
          }
    return res;
         
    }
};