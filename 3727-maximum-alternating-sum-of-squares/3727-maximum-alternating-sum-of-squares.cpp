class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(auto& ele:nums) ele*=ele;

        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        //small then large

        int x=n/2;
        long long small=accumulate(nums.begin(),nums.begin()+x,0LL);
        long long large=accumulate(nums.begin()+x,nums.end(),0LL);
        return large-small;
    }
};