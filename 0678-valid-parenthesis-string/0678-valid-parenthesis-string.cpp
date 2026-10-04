class Solution {
public:
    int n;
    // bool solve(int i, string& s,int count){
    //     if(i>=n){
    //         if(count==0) return true;
    //         else return false;
    //     } 
    //     if(count<0) return false;

    //     if(s[i]=='('){ 
    //         if(solve(i+1,s,count+1)) return true;
    //     }
    //     else if(s[i]==')') {
    //         if(solve(i+1,s,count-1)) return true;
    //     }
    //     else{
    //         bool empty=solve(i+1,s,count); if(empty) return true;
    //         bool take_as_open=solve(i+1,s,count+1); if(take_as_open) return true;
    //         bool take_as_close=solve(i+1,s,count-1); if(take_as_close) return true;
    //     }
    //     return false;
    // }

    bool solveUsingMemo(vector<vector<int>>& dp, int i, string& s, int count){
        if(i>=n){
            if(count==0) return true;
            else return false;
        } 
        if(count<0) return false;

        if(dp[i][count]!=-1) return dp[i][count];
        if(s[i]=='('){ 
            if(solveUsingMemo(dp,i+1,s,count+1)) return dp[i][count]=true;
        }
        else if(s[i]==')') {
            if(solveUsingMemo(dp,i+1,s,count-1)) return dp[i][count]=true;;
        }
        else{
            bool empty=solveUsingMemo(dp,i+1,s,count); if(empty) return dp[i][count]=true;;
            bool take_as_open=solveUsingMemo(dp,i+1,s,count+1); if(take_as_open) return dp[i][count]=true;;
            bool take_as_close=solveUsingMemo(dp,i+1,s,count-1); if(take_as_close) return dp[i][count]=true;;
        }
        return dp[i][count]=false;
    }

    bool checkValidString(string s) {
        n=s.size();
        // return solve(0,s,0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solveUsingMemo(dp,0,s,0);
    }
};