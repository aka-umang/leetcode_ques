class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>m; //<val,idx>
       vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
        int rem=target-nums[i];

        if(m.find(rem)==m.end()){//nhi mila in map
        m[nums[i]]=i;
        }
        else{
          ans.push_back(m[rem]);
          ans.push_back(i);
        }
       }
       return ans;
    }
};