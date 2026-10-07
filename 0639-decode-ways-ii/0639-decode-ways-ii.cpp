class Solution {
public:
    int M=1e9+7;
    int n;

    bool digit(char &ch) {return ch>='0' && ch<='9';}
    bool star(char& ch)  {return ch=='*';}
    
    long long solve(vector<int>& dp,string &s, int i){
        if(i==n) return 1;
        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i];
        //as single 

        long long count=solve(dp,s,i+1);

        if(star(s[i])) {
            long long nextCount = (8LL * solve(dp,s, i + 1) )% M; // 2 - 9
            count = (count + nextCount) % M;
        }
        
        //as double

        if(i+1<n){
            //dd
            if(digit(s[i + 1]) && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                count = (count + solve(dp,s, i + 2)) % M; // 10 - 26
            }

            //*d 
            else if(star(s[i]) && digit(s[i+1])){
                count=(count+solve(dp,s,i+2))%M;  //10-19

                if(s[i+1]<='6') count=(count+solve(dp,s,i+2))%M;  //20-26
            }

            //d*
            else if(star(s[i+1]) && digit(s[i])){
                if(s[i]=='1') count=(count+9LL*solve(dp,s,i+2))%M;  //10-19

                else if(s[i]=='2') count=(count+6LL*solve(dp,s,i+2))%M;  //20-26
            }

            //**
            else if(star(s[i]) && star(s[i+1])){
                int nxtCount=(9LL*solve(dp,s,i+2))%M; //11-19
                count=(count+nxtCount)%M;
 
                int nxtCount2=(6LL*solve(dp,s,i+2))%M; //20-26
                count=(count+nxtCount2)%M;
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