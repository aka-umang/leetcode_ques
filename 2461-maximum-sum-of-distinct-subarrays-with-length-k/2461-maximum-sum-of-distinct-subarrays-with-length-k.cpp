class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>s;
        int i=0,j=0;
        long long maxi=0;
        long long sum=0;
        while(j<n){
            while(s.count(nums[j])){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            
            s.insert(nums[j]);
            sum+=nums[j];

            if(j-i+1==k){
                maxi=max(sum,maxi);
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }

            j++;
        }
        return maxi;
    }
};