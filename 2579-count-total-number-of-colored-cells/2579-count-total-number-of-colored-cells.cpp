class Solution {
public:
    long long coloredCells(int n) {
        long long int val=1;
        for(int i=1;i<n;i++){
            val+=(i*4);

        }
        return val;

    }
};