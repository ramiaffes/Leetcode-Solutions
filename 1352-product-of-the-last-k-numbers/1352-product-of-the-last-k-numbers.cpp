class ProductOfNumbers {
public:
    vector<int>dp;
    int size=0;
    int p=0;
    map<int,int>map;
    ProductOfNumbers() {
        dp.clear();
        size=0;
        p=0;
        map.clear();
    }
    
    void add(int num) {
        if(size==0){
            dp.push_back(num);
            map[p]=p;
        }
        else if (dp[size-1]==0){
            dp.push_back(num);
            p=size;
            map[size]=p;
        }
        else{
            dp.push_back(dp[size-1]*num);
            map[size]=p;
        }
    size++;
    }
    
    int getProduct(int k) {
        if(dp[size-1]==0){
            return 0;
        }
        else if (map[size-1]<=(size-k-1)){
            return dp[size-1]/dp[size-k-1];
            
        }
        else{
            if(map[size-1]==(size-k)){
                return dp[size-1];
            }
        }
    return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */