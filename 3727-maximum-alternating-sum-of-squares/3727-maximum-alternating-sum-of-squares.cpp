class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(auto& ele:nums) ele*=ele;
        sort(nums.begin(), nums.end(), greater<int>());
       
        int x=(n+1)/2;
        long long large=accumulate(nums.begin(),nums.begin()+x,0LL);
        long long small=accumulate(nums.begin()+x,nums.end(),0LL);
        return large-small;
    }
};