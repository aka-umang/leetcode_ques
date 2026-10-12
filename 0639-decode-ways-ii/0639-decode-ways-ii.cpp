class Solution {
public:
    int n;
    int MOD=1e9+7;

    bool isStar(char& ch) {return ch=='*';}
    
    int solve(vector<int>&dp ,string&s ,int i){
        if(i>=n) return 1;
        if(s[i]=='0') return dp[i]=0;
        
        if(dp[i]!=-1) return dp[i];

        //1->9
        long long count=solve(dp,s,i+1);
        if(isStar(s[i]))  {count=(count+8LL*solve(dp,s,i+1))%MOD;}
            
        if(i+1<n){
            // dd
            if(isdigit(s[i+1]) && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) {
                count=(count+1LL*solve(dp,s,i+2))%MOD;
            }
            else if(isStar(s[i+1])){ 
                //1* , **
                if(s[i]=='1' || isStar(s[i]))   {count=(count+9LL*solve(dp,s,i+2))%MOD;}
                //2* , **
                if(s[i]=='2' || isStar(s[i]))  { count=(count+6LL*solve(dp,s,i+2))%MOD;}
            }//*d
            else if(isStar(s[i]) && isdigit(s[i+1])){
                count=(count+1LL*solve(dp,s,i+2))%MOD; //1d
                if(s[i+1]<='6') count=(count+1LL*solve(dp,s,i+2))%MOD; //2d   
            }
        }
        return dp[i]=count;
    }

    int numDecodings(string s) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(dp,s,0);
    }
};