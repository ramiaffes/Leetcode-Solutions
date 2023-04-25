map<string,int>hashing;
map<string,int>hashing1;
string res;
class MapSum {
public:
    MapSum() {
        hashing.clear();
        hashing1.clear();
        
    }
    
    void insert(string key, int val) {
       res.clear();
        for(int i=0;i<key.length();i++){
             
            string var(1,key[i]);
            res.append(var);
            hashing1[res]-=hashing[key];
            hashing1[res]+=val;
        } hashing[key]=val;
    }
    
    int sum(string prefix) {
        return hashing1[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */