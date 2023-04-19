map<int,set< int>>adj;
const long long int N=1e6;
map<int, bool>vis;
int val=0;
map<int,int>val1;
void dfs( int u){
	if(vis[u]==1){return;}
	vis[u]=1;
    val1[u]=val;
	for(auto v:adj[u]){
		dfs(v);
		}
	}
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
 vis.clear();
        val1.clear();
        val=0;
        adj.clear();
        int n=*max_element(nums.begin(),nums.end());
         bool prime[n + 1];
        map<int,set<int>>res;
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1]=false;
        map<int,bool>vis1;
        for(int i=0;i<nums.size();i++){
            if(vis1[nums[i]]==1)continue;
            vis1[nums[i]]=1;
            for(int j=1;j*j<=nums[i];j++){
                if((nums[i]%j==0)){
                    if(prime[j]){
                    adj[j].insert(nums[i]); 
                    adj[nums[i]].insert(j);}
                    if(prime[nums[i]/j]){
                    adj[nums[i]/j].insert(nums[i]);
                        adj[nums[i]].insert(nums[i]/j);
                    }
                }
              
                
                   
                
            }
        }
    val=0;
    for(int i=0;i<nums.size();i++){
        if(vis[nums[i]]==0){
            dfs(nums[i]);
            val++;
        }
    }
    vector<int>nums1(nums.begin(),nums.end());
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(val1[nums[i]]!=val1[nums1[i]]){
            return false;
        }
    }
    return true;
    
    
    }
};