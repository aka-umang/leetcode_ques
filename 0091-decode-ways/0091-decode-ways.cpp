class Solution {
public:
    int n;
    int solveRec(string &s){
        int dp_i_plus_1=1; // dp[n]=1;
        int dp_i_plus_2=1;
        int dp_i=0;

        for(int i=n-1;i>=0;i--){
            int takeAsSingle=0;
            int takeAsDouble=0;

            if(s[i]!='0') takeAsSingle+=dp_i_plus_1;
            else {
                dp_i=0;
                dp_i_plus_2=dp_i_plus_1;
                dp_i_plus_1=0;
                continue;
            }
            
            if(i+1<n){
                int ele=(s[i]-'0')*10+(s[i+1]-'0');
                if(ele>0 && ele<=26){
                    takeAsDouble+=dp_i_plus_2;
                }
            }
            dp_i=takeAsDouble+takeAsSingle;  
            
            dp_i_plus_2=dp_i_plus_1;
            dp_i_plus_1=dp_i;  
            
        } 

        return dp_i;
    }

    int numDecodings(string s) {
        n=s.size();
        return solveRec(s);
    }
};