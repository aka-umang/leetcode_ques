class Solution {
public:
    int n;
    int solveRec(vector<int> &dp,string &s,int i){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];

        int takeAsSingle=0;
        int takeAsDouble=0;

        if(s[i]!='0'){ //single toh ban hi jayega
            takeAsSingle+=solveRec(dp,s,i+1);
        }
        else return 0;
        
        if(i+1<n){
            int ele=(s[i]-'0')*10+(s[i+1]-'0');
            if(ele>0 && ele<=26){
                takeAsDouble+=solveRec(dp,s,i+2);
            }
        }
        return dp[i]=takeAsDouble+takeAsSingle;
    }

    int numDecodings(string s) {
        n=s.size();
        vector<int> dp(n,-1);
        return solveRec(dp,s,0);
    }
};