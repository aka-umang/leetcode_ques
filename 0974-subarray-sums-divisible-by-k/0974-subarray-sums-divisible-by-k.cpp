class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp; mp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=sum%k;
            if(temp<0) temp+=k;
            
            ans+=(!mp.count(temp))?0:mp[temp];
            mp[temp]++;
        }
        return ans;
    }
};