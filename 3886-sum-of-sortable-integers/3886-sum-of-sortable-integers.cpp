class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int k=1;k<=n;k++){ //O(n^1/2)--->root(n)
            if(n%k) continue;
            int old_maxi=INT_MIN;
            bool flag=true;
            for(int i=0;i<n && flag;i+=k){ //O(n)
                int j=i;
                int count=0;
                int curr_maxi=INT_MIN;
                while(j<i+k && count<2){
                    curr_maxi=max(curr_maxi,nums[j]);

                    //find break point nums[i]>nums[i>] ese count krloh.
                    if(j==i+k-1 && nums[j]>nums[i]) count++;
                    else if(j<i+k-1 && nums[j]>nums[j+1]) count++;

                    //each element of subarray is smaller then previous subarray maximum.
                    if((i!=0 && old_maxi>nums[j]) || count>1){
                        count+=5;
                        flag=false;
                    } 
                    j++;
                }
                old_maxi=curr_maxi;
            }
            if(flag) ans+=k;
        }
        return ans;
    }
};