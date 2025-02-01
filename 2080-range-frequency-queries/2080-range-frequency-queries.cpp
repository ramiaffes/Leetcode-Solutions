class RangeFreqQuery {
public:
    vector<int> A;
    vector<map<int,int>> ST;

    void build(int node, int L, int R)
{

    // Leaf node where L == R
    if (L == R) {
        ST[node][A[L]]++;
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
        for(auto v:ST[2 * node])
        ST[node][v.first] = ST[2 * node][v.first] + ST[2 * node + 1][v.first];
        for(auto v:ST[2 * node+1])
        ST[node][v.first] = ST[2 * node][v.first] + ST[2 * node + 1][v.first];
    }
}
int query2(int node, int tl, int tr, int l, int r,int value)
{

    // If it lies out of range then
    // return 0
    if (r < tl or tr < l)
        return 0;

    // If the node contains the range then
    // return the node value
    if (l <= tl and tr <= r){
        return ST[node][value];}
    int tm = (tl + tr) / 2;

    // Recursively traverse left and right
    // and find the node
    return query2(2 * node, tl, tm, l, r,value)+query2(2 * node + 1, tm + 1, tr, l, r,value);
   
} 
    RangeFreqQuery(vector<int>& arr) {
        A=arr;
        ST.clear();
        ST.resize(4 * arr.size());
        build(1,0,arr.size()-1);
    }
    
    int query(int left, int right, int value) {
        return query2(1,0,A.size()-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */