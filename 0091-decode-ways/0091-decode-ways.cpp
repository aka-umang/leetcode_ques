class Solution {
public:
    int n;
    int solve(vector<int>&dp ,string &s, int i) {
        if(i>=n) return 1;
        if(s[i]=='0') return dp[i]=0;
        if(dp[i]!=-1) return dp[i];

        //1->9
        int count=solve(dp,s,i+1);

        //10->19
        if(i+1<n && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){
            count+=solve(dp,s,i+2);
        } 

        return dp[i]=count;
    }
    int numDecodings(string s) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(dp,s,0);  
    }
};