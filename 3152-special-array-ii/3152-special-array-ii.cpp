class Solution {
public:
    
vector<int> A;
vector<bool> ST;

    void build(int node, int L, int R)
{

    // Leaf node where L == R
    if (L == R) {
        ST[node] = true;
    }
    else {

        // Find the middle element to
        // split the array into two halves
        int mid = (L + R) / 2;

        // Recursively travel the
        // left half
        build(2 * node, L, mid);

        // Recursively travel the
        // right half
        build(2 * node + 1, mid + 1, R);

        // Storing the sum of both the
        // children into the parent
        ST[node] = ST[2 * node] and ST[2 * node + 1] and (A[mid]%2!=A[mid+1]%2);
        
    }
} 
map<int,bool>vis;
bool query(int node, int tl, int tr, int l, int r)
{

    // If it lies out of range then
    // return 0
    if (r < tl or tr < l)
        return true;

    // If the node contains the range then
    // return the node value
    if (l <= tl and tr <= r){
        vis[tl]=1;
        vis[tr]=1;
        return ST[node];}
    int tm = (tl + tr) / 2;

    // Recursively traverse left and right
    // and find the node
    bool val1=query(2 * node, tl, tm, l, r);
    bool val2=query(2 * node + 1, tm + 1, tr, l, r);
    bool res=val1 and val2;
    if((vis[tm]==1)and(vis[tm+1]==1))
    return res  and (A[tm]%2!=A[tm+1]%2);
    else return res;
}
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       A=nums;
       ST.resize(4 * nums.size());
    build(1, 0, nums.size() - 1);
    vector<bool>answers(queries.size());
   
    for(int i=0;i<queries.size();i++){
        vis.clear();
        answers[i]=query(1, 0, nums.size() - 1, queries[i][0], queries[i][1]);
    }
        return answers;
    }
};