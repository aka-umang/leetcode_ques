class NumArray {
public:
    vector<int>prefix;

    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix.resize(n); prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum= prefix[right];
        if(left>0) sum-=prefix[left-1];
        return sum;
    }
};