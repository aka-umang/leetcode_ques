class Solution {
public:
    int n;
    int solve(string &s) {
        vector<int>dp(n+1,-1);
        dp[n]=1;
        // if(s[i]=='0') return dp[i]=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            
            int count=dp[i+1]; //1->9 
            if(i+1<n && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){  //10->19
                count+=dp[i+2];
            } 
            dp[i]=count;
        }
        return dp[0];
    }
    
    int numDecodings(string s) {
        n=s.size();
        return solve(s);  
    }
};