class SmallestInfiniteSet {
public:
    map<int,int>hashing;
    int val=1;
    SmallestInfiniteSet() {
        hashing.clear();
        val=1;
    }
    
    int popSmallest() {
        hashing[val]=1;
        int val1=val;
        while(hashing[val]==1){
        val++;}
        return val1;
    }
    
    void addBack(int num) {
        if(hashing[num]==1){
            hashing[num]=0;
            val=min(val,num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */