class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
       
        int maxSubSum=nums[0];
        int minSubSum=nums[0];

        int sum1=0;
        int sum2=0;

        for(int& ele: nums){
            totalSum+=ele;

            //for finding maxSubarr sum [0-->n-1]
            sum1+=ele;
            maxSubSum=max(maxSubSum,sum1);
            if(sum1<0) sum1=0;  

            //min subarray sum from [0-->n-1]
            if(sum2+ele>ele) sum2=ele;
            else  sum2+=ele;
            minSubSum=min(minSubSum,sum2);
        }
        if(totalSum-minSubSum==0) return maxSubSum;
        return max(maxSubSum,totalSum-minSubSum);
    }
};