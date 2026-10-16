class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int>deq;
        int i=0,j=0;

        while(j<n){
            while(!deq.empty() && nums[deq.back()]<=nums[j]) deq.pop_back();

            deq.push_back(j);

            if(j-i+1==k){
                ans.push_back(nums[deq.front()]);
                if(!deq.empty() && deq.front()<=i) {
                    deq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};