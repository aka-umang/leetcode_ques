class Solution {
public:
    int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        vector<int>NSE(n,0);
        
        stack<int>st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            NSE[i]=(st.empty())?n-i:st.top()-i;
            st.push(i);
            i--;
        }

        stack<int>pt;
        i=0;
        while(i<n){
            while(!pt.empty() && arr[pt.top()]>arr[i]) pt.pop();
            int t=(pt.empty())?i+1:i-pt.top();
            ans=(ans+ 1LL* arr[i]* NSE[i]* t)%MOD;
            pt.push(i);
            i++;
        }
        return ans;
    }
};