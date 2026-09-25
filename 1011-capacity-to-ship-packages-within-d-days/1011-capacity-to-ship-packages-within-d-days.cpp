class Solution {
public:
    bool isValid(int mid,vector<int>& weights,int days){
        int count=0;
        int n=weights.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            if(count>days) return false;
            sum+=weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
                if(sum>mid) return false;
            }
        }
        count++;
        return count<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int i=1;
        int j=0;
        for(int& ele: weights) {
            i=max(i,ele);
            j+=ele;
        }

        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isValid(mid,weights,days)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};