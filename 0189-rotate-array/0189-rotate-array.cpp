class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>dq(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            int val=dq.back();
            dq.pop_back();
            dq.push_front(val);
        }
    vector<int>nums1(dq.begin(),dq.end());
        nums=nums1;
    }
};