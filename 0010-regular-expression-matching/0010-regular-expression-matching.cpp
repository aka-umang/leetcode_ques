class Solution {
public:
    bool solve(string &s, string &p, int i, int j,vector<vector<int>>&dp){
        int n=s.size();
        int m=p.size();
        if(i>=n && j>=m) return dp[i][j]=true;
        if(j>=m) return dp[i][j]=false;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j]=='.'){
            if(j+1<m && p[j+1]=='*'){
                if(solve(s,p,i,j+1,dp)) return dp[i][j]=true;
            }
            else if(i<n){
                if(solve(s,p,i+1,j+1,dp)) return dp[i][j]=true;
            }
        }

        else if(p[j]=='*'){

            //not take
            if(solve(s,p,i,j+1,dp)) return dp[i][j]=true;

            char prev=p[j-1];
            //Take
            if(i<s.size() && prev=='.'){
                if(solve(s,p,i+1,j,dp)) return dp[i][j]=true;
            }
            else if(i<s.size() && prev==s[i]){
                if(solve(s,p,i+1,j,dp)) return dp[i][j]=true;
            }
        }
        else{
            if(j+1<p.size() && p[j+1]=='*'){
                if(solve(s,p,i,j+1,dp)) return dp[i][j]=true;
            }
            else if(s[i]==p[j]) if(solve(s,p,i+1,j+1,dp)) return dp[i][j]=true;
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0,dp);
    }
};